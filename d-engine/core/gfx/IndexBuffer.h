#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H
#include <glad/glad.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct IndexBuffer {
    uint32_t rendererID;
} IndexBuffer;

IndexBuffer* IndexBuffer_Create(float* data, uint32_t size);
void IndexBuffer_Delete(IndexBuffer* vb);
void IndexBuffer_Bind(IndexBuffer* vb);
void IndexBuffer_Unbind(IndexBuffer* vb);

#endif
