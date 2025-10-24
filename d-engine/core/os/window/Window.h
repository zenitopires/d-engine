#pragma once
#include <stdbool.h>
#include <SDL3/SDL.h>
#include "WindowProperties.h"

typedef struct WindowData {
    const char* Title;
    unsigned int width, height;
    bool Vsync;
   	SDL_Window* window;
	SDL_GLContext context;
	SDL_Event event;
} WindowData;

WindowData* Window_Create(WindowProps* windowProperties);
void Window_Delete(WindowData* windowData);
void Window_Initialize(WindowData* windowData);
void Window_OnUpdate(WindowData* wd, bool* appRunning);
