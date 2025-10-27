#pragma once
#include <cglm/cglm.h>
#include "d-engine/core/gfx/VertexArray.h"

typedef struct Renderable {
    VertexArray* vao;
} Renderable;

typedef struct Renderer {

} Renderer;

Renderer* Renderer_Create(void);
void Renderer_Delete(Renderer* renderer);
void Renderer_Clear(vec4 color);
void Renderer_Draw(VertexArray* vao);
