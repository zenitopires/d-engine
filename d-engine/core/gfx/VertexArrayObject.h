#ifndef VERTEX_ARRAY_OBJECT_H
#define VERTEX_ARRAY_OBJECT_H
#include "d-engine/core/gfx/IndexBuffer.h"
#include "d-engine/core/gfx/VertexBuffer.h"
#include <glad/glad.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct VertexArrayObject {
    uint32_t rendererID;
} VertexArrayObject;

VertexArrayObject* VertexArrayObject_Create();
void VertexArrayObject_Attach_Buffers(VertexBuffer* vb, IndexBuffer* ib);
void VertexArrayObject_Attribute();
void VertexArrayObject_Delete(VertexArrayObject* vao);
void VertexArrayObject_Bind(VertexArrayObject* vao);
void VertexArrayObject_Unbind();

#endif
