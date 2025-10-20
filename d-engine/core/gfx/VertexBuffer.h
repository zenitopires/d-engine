#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glad/glad.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct VertexBuffer {
    uint32_t rendererID;
} VertexBuffer;

VertexBuffer* VertexBuffer_Create(float* data, uint32_t size);
void VertexBuffer_Delete(VertexBuffer* vb);
void VertexBuffer_Bind(VertexBuffer* vb);
void VertexBuffer_Unbind(VertexBuffer* vb);

#endif
