#pragma once
#include <cglm/cglm.h>
#include "d-engine/Core/GFX/VertexArray.h"

typedef struct Renderable {
    VertexArray* vao;
    vec3 position;
    mat4 transform;
} Renderable;

typedef struct Renderer {
    Renderable* renderables;
    size_t size;
    size_t capacity;
} Renderer;

Renderer* Renderer_Create(void);
void Renderer_Submit(Renderer* renderer, Renderable* renderable);
void Renderer_Delete(Renderer* renderer);
void Renderer_Clear(vec4 color);
void Renderer_Draw(Renderer* renderer);
