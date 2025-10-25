#pragma once
#include <stdint.h>
#include <glad/glad.h>
#include "d-engine/core/gfx/Buffer.h"

// VertexArray represents an OpenGL vertex array object.
typedef struct VertexArray {
    // rendererID is the name of vertex array object.
    uint32_t rendererID;
    uint32_t indicesCount;
} VertexArray;

// VertexArray_Create creates a vertex array object.
VertexArray* VertexArray_Create();
// VertexArray_Attach_Buffers attaches a provided vertex buffer object and optionally an index buffer object to a vertex array object.
void VertexArray_Attach_Buffers(VertexArray* vao, Buffer* vb, Buffer* ib);
// VertexArray_Attribute defines the data layout for the vertex array object.
void VertexArray_Attribute();
// VertexArray_Delete deletes the provided vertex array object.
void VertexArray_Delete(VertexArray* vao);
// VertexArray_Bind binds the provided vertex array object.
void VertexArray_Bind(VertexArray* vao);
// VertexArray_Unbind unbinds a previously bounded vertex array object.
void VertexArray_Unbind();
