#include <stdlib.h>
#include "d-engine/core/os/window/WindowProperties.h"
#include "d-engine/core/os/window/Window.h"
#include "d-engine/core/gfx/Buffer.h"
#include "d-engine/core/gfx/VertexArray.h"
#include "d-engine/core/gfx/Shader.h"
#include "d-engine/core/gfx/Renderer.h"
#include "d-engine/core/log/Log.h"
#include "Application.h"

Application* Application_Create() {
    debug_msg("Entering Application_Create");
    info_msg("Creating application instance!");
    Application* app = malloc(sizeof(Application));
    if (!app) {
        error_msg("Failed to allocate memory for the application!");
        return nullptr;
    }
    return app;
}

void Application_Run(Application* app) {
    log_info("Running application!");
    WindowProps wp = WindowProps_Create("Zen", 1280, 720, true);
    WindowData* wd = Window_Create(&wp);
    Window_Initialize(wd);

    bool appRunning = true;

    float vertices[] = {
			 0.5f,  0.5f, 0.0f,  // top right
			 0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f,  // top left
			 0.3f,  0.2f, 0.25f
		};
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	Shader* shaderProgram = Shader_Create("assets/shaders/defaults/vertex.vert",
	    "assets/shaders/defaults/fragment.frag");
	Shader_Bind(shaderProgram);

	VertexArray* vao = VertexArray_Create();

    Buffer* vb = Buffer_Create(GL_ARRAY_BUFFER, vertices, sizeof(vertices));
    Buffer* ib = Buffer_Create(GL_ELEMENT_ARRAY_BUFFER, indices, sizeof(indices));

    VertexArray_Attach_Buffers(vao, vb, ib);
    VertexArray_Attribute();

    vec4 color = {0.2f, 0.3f, 0.3f, 1.0f};

    while (appRunning)
    {
        Window_OnUpdate(wd, &appRunning);
		Renderer_Clear(color);
		Renderer_Draw(vao, shaderProgram);
    }
    log_info("Exiting application! Cleaning up resources...");
    Window_Delete(wd);
    Buffer_Delete(vb);
    Buffer_Delete(ib);
    VertexArray_Delete(vao);
    Shader_Delete(shaderProgram);
}
