#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glad/glad.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// VertexBuffer represents an OpenGL vertex buffer object.
typedef struct VertexBuffer {
    // rendererID is the name of the vertex buffer object.
    uint32_t rendererID;
} VertexBuffer;

// VertexBuffer_Create creates a vertex buffer object with the provided data and size.
VertexBuffer* VertexBuffer_Create(float* data, uint32_t size);
// VertexBuffer_Delete deletes the provided vertex buffer object.
void VertexBuffer_Delete(VertexBuffer* vb);
// VertexBuffer_Bind binds a vertex buffer object.
void VertexBuffer_Bind(VertexBuffer* vb);
// VertexBuffer_Unbind unbinds a previously bounded vertex buffer object.
void VertexBuffer_Unbind(void);

#endif
