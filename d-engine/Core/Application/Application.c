#include <stdlib.h>
#include "cglm/mat4.h"
#include "d-engine/Core/GFX/Renderer.h"
#include "d-engine/Core/OS/Window/WindowProperties.h"
#include "d-engine/Core/OS/Window/Window.h"
#include "d-engine/Core/GFX/VertexArray.h"
#include "d-engine/Core/Log/Log.h"
#include "Application.h"

Application* Application_Create(GameContext* gameContext) {
    debug_msg("Entering Application_Create");
    info_msg("Creating application instance!");
    Application* app = malloc(sizeof(Application));
    app->gameContext = malloc(sizeof(GameContext));
    if (gameContext) {
        app->gameContext = gameContext;
    }
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

	VertexArray* vao = VertexArray_Create(app->gameContext->objects);

	mat4 matrix;
	glm_mat4_identity(matrix);

	vec3 position = {0.5, 0.3, 0.0};

	Renderable* renderable = malloc(sizeof(Renderable));
	renderable->vao = vao;
	glm_vec3_copy(position, renderable->position);
	glm_mat4_copy(matrix, renderable->transform);

	Renderer_Submit(renderer, renderable);

    vec4 color = {0.2f, 0.3f, 0.3f, 1.0f};

    while (appRunning)
    {
        Window_OnUpdate(wd, &appRunning);
        if (app->gameContext != nullptr && app->gameContext->OnUpdate != nullptr) {
            log_debug("Game context is active");
        }
		Renderer_Clear(color);
		Renderer_Draw(renderer);
    }
    log_info("Exiting application! Cleaning up resources...");
    Window_Delete(wd);
    // VertexArray_Delete(vao);
}
