#include <stdlib.h>
#include "d-engine/Core/OS/Window/WindowProperties.h"
#include "d-engine/Core/OS/Window/Window.h"
#include "d-engine/Core/GFX/VertexArray.h"
#include "d-engine/Core/GFX/Renderer.h"
#include "d-engine/Core/Log/Log.h"
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

    Renderer* renderer = Renderer_Create();

    bool appRunning = true;

    float vertices[] = {
         0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 0.5f, 0.5f, 0.5f
    };

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	Data* data = malloc(sizeof(Data));
	data->vertexData = vertices;
	data->indexData = indices;
	data->vertexCount = sizeof(vertices) / sizeof(float);
	data->indexCount = sizeof(indices) / sizeof(unsigned int);

	VertexArray* vao = VertexArray_Create(data);

	Renderable* renderable = malloc(sizeof(Renderable));
	renderable->vao = vao;

	Renderer_Submit(renderer, vao);

    vec4 color = {0.2f, 0.3f, 0.3f, 1.0f};

    while (appRunning)
    {
        Window_OnUpdate(wd, &appRunning);
		Renderer_Clear(color);
		Renderer_Draw(renderer);
    }
    log_info("Exiting application! Cleaning up resources...");
    Window_Delete(wd);
    VertexArray_Delete(vao);
}
