#include <stdlib.h>
#include <glad/glad.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL.h>
#include "SDL3/SDL_opengl.h"
#include "d-engine/Core/Log/Log.h"
#include "Window.h"

bool s_SDLInitialized = false;

WindowData* Window_Create(WindowProps* windowProperties) {
    WindowData* wd = malloc(sizeof(WindowData));
    if (!wd) {
        return nullptr;
    }
    wd->Title = windowProperties->Title;
    wd->width = windowProperties->Width;
    wd->height = windowProperties->Height;
    wd->Vsync = windowProperties->Vsync;
    wd->window = nullptr;
    wd->context = nullptr;
    return wd;
}

void Window_Delete(WindowData* wd) {
    SDL_DestroyWindow(wd->window);
    SDL_Quit();
}

void Window_Initialize(WindowData* windowData) {
    if (!s_SDLInitialized) {
        int success = SDL_Init(SDL_INIT_VIDEO);
        if (success < 0) {
            exit(-1);
        }
        s_SDLInitialized = true;
    }

   	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	windowData->window = SDL_CreateWindow(windowData->Title,
				windowData->width, windowData->height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
				// This should depend upon the renderer's configurations
				/*SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE*/
	);

	if (!windowData->window) {
	    SDL_Quit();
		exit(-1);
	}

	windowData->context = SDL_GL_CreateContext(windowData->window);
	if (!windowData->context) {
        SDL_Quit();
        exit(-1);
	}

	if (windowData->Vsync) {
        SDL_GL_SetSwapInterval(1);
	} else {
        SDL_GL_SetSwapInterval(0);
	}

	if (!SDL_GL_MakeCurrent(windowData->window, windowData->context)) {
		SDL_Quit();
		exit(-1);
	}

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
	    SDL_Quit();
		exit(-1);
	}
}

void Window_OnUpdate(WindowData* wd, bool* appRunning) {
    SDL_GL_SwapWindow(wd->window);
    while (SDL_PollEvent(&wd->event)) {
       	switch (wd->event.type)
			{
			case SDL_EVENT_QUIT:
			{
				*appRunning = false;
				break;
			}
			case SDL_EVENT_WINDOW_RESIZED:
			{
			    unsigned int width = wd->event.window.data1;
				unsigned int height = wd->event.window.data2;
			    debug_msg("Window resized, width: %d, height: %d", width, height);
				glViewport(0, 0, width, height);
				// std::cout << m_Data.Event.window.data1 << " " << m_Data.Event.window.data2 << '\n';
				break;
			}
			case SDL_EVENT_WINDOW_MINIMIZED:
			{
				// std::cout << "Window has been minimized\n";
				break;
			}
			case SDL_EVENT_WINDOW_MAXIMIZED:
			{
				// std::cout << "Window has been maximized\n";
				break;
			}
			}
    }
}
