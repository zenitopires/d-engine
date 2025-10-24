#include "Application.h"
#include "d-engine/core/gfx/IndexBuffer.h"
#include "d-engine/core/os/window/WindowProperties.h"
#include "d-engine/core/os/window/Window.h"
#include "d-engine/core/gfx/VertexBuffer.h"
#include "d-engine/core/gfx/VertexArrayObject.h"
#include "d-engine/core/gfx/Shader.h"
#include "d-engine/core/gfx/Renderer.h"
#include <log.h>
#include <stdlib.h>

Application* Application_Create() {
    log_info("Creating application instance!");
    Application* app = malloc(sizeof(Application));
    if (!app) {
        log_error("Failed to allocate memory for the application!");
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

	VertexArrayObject* vao = VertexArrayObject_Create();

    VertexBuffer* vb = VertexBuffer_Create(vertices, sizeof(vertices));
    IndexBuffer* ib = IndexBuffer_Create(indices, sizeof(indices));

    VertexArrayObject_Attach_Buffers(vb, ib);
    VertexArrayObject_Attribute();

    vec4 color = {0.2f, 0.3f, 0.3f, 1.0f};

    while (appRunning)
    {
        Window_OnUpdate(wd, &appRunning);
		Renderer_Clear(color);
		VertexArrayObject_Bind(vao);
		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);
    }
    log_info("Exiting application! Cleaning up resources...");
    Window_Delete(wd);
    VertexBuffer_Delete(vb);
    IndexBuffer_Delete(ib);
    VertexArrayObject_Delete(vao);
    Shader_Delete(shaderProgram);
}
