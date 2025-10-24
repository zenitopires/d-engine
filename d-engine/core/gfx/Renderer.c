#include "Renderer.h"
#include <glad/glad.h>
#include <stdlib.h>

Renderer* Renderer_Create() {
    Renderer* renderer = malloc(sizeof(Renderer));
    if (!renderer) {
        return nullptr;
    }
    return renderer;
}

void Renderer_Clear(vec4 color) {
    glClearColor(color[0], color[1], color[2], color[3]);
	glClear(GL_COLOR_BUFFER_BIT);
}
