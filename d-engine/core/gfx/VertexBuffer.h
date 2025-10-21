#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glad/glad.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct VertexBuffer {
    uint32_t rendererID;
} VertexBuffer;

// VertexBufferCreate creates a vertex buffer object with given data and size.
VertexBuffer* VertexBuffer_Create(float* data, uint32_t size);
// VertexBufferDelete deletes a vertex buffer object.
void VertexBuffer_Delete(VertexBuffer* vb);
// VertexBuffer_Bind binds a vertex buffer object. The buffer object name is stored in vb->rendererID.
void VertexBuffer_Bind(VertexBuffer* vb);
// VertexBuffer_Unbind unbinds a previously bounded vertex buffer object.
void VertexBuffer_Unbind(VertexBuffer* vb);

#endif
