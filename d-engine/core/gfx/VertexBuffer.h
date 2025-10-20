#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glad/glad.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct VertexBuffer {
    uint32_t rendererID;
} VertexBuffer;

VertexBuffer* VertexBufferCreate(float* data, uint32_t size);
void VertexBufferDelete(VertexBuffer* vb);

#endif
