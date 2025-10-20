#include "WindowProperties.h"
#include <stdlib.h>

WindowProps WindowPropsCreate(const char* title, unsigned int width, unsigned int height, bool vsync) {
    WindowProps wp;
    wp.Width = width;
    wp.Height = height;
    wp.Title = title;
    wp.Vsync = vsync;
    return wp;
}
