#ifndef WINDOW_H
#define WINDOW_H
#include "WindowProperties.h"
#include <SDL3/SDL.h>
#include <stdbool.h>

typedef struct WindowData {
    const char* Title;
    unsigned int width, height;
    bool Vsync;
   	SDL_Window* window;
	SDL_GLContext context;
	SDL_Event event;
} WindowData;

WindowData* WindowCreate(WindowProps* windowProperties);
void WindowDelete(WindowData* windowData);
void InitializeWindow(WindowData* windowData);
void WindowOnUpdate(WindowData* wd, bool* appRunning);

#endif
