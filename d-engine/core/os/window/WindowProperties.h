#ifndef WINDOW_PROPERTIES_H
#define WINDOW_PROPERTIES_H
#include <stdbool.h>

typedef struct WindowProps {
    const char* Title;
    unsigned int Width, Height;
    bool Vsync;
} WindowProps;

WindowProps WindowProps_Create(const char* title, unsigned int width, unsigned int height, bool vsync);

#endif
