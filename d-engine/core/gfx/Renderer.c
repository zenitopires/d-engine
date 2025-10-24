#include "Renderer.h"
#include "glad/glad.h"

Renderer* Renderer_Create() {
    Renderer* renderer = malloc(sizeof(Renderer));
    if (!renderer) {
        return nullptr;
    }
    return renderer;
}

void Renderer_Clear(vec4 color) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
