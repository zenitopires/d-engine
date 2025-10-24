#pragma once

#include "d-engine/core/gfx/IndexBuffer.h"
#include "d-engine/core/gfx/VertexBuffer.h"
#include <glad/glad.h>
#include <stdint.h>
#include <stdlib.h>

// VertexArrayObject represents an OpenGL vertex array object.
typedef struct VertexArrayObject {
    // rendererID is the name of vertex array object.
    uint32_t rendererID;
} VertexArrayObject;

// VertexArrayObject_Create creates a vertex array object.
VertexArrayObject* VertexArrayObject_Create();
// VertexArrayObject_Attach_Buffers attaches a provided vertex buffer object and optionally an index buffer object to a vertex array object.
void VertexArrayObject_Attach_Buffers(VertexBuffer* vb, IndexBuffer* ib);
// VertexArrayObject_Attribute defines the data layout for the vertex array object.
void VertexArrayObject_Attribute();
// VertexArrayObject_Delete deletes the provided vertex array object.
void VertexArrayObject_Delete(VertexArrayObject* vao);
// VertexArrayObject_Bind binds the provided vertex array object.
void VertexArrayObject_Bind(VertexArrayObject* vao);
// VertexArrayObject_Unbind unbinds a previously bounded vertex array object.
void VertexArrayObject_Unbind();
