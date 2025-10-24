#pragma once
#include "d-engine/core/gfx/Shader.h"
#include "d-engine/core/gfx/VertexArrayObject.h"
#include <cglm/cglm.h>

typedef struct Renderer {

} Renderer;

Renderer* Renderer_Create(void);
void Renderer_Delete(Renderer* renderer);
void Renderer_Clear(vec4 color);
void Renderer_Draw(VertexArrayObject* vao, Shader* shader);
