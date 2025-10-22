#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H
#include <glad/glad.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct IndexBuffer {
    uint32_t rendererID;
} IndexBuffer;

IndexBuffer* IndexBuffer_Create(unsigned int* data, uint32_t size);
void IndexBuffer_Delete(IndexBuffer* ib);
void IndexBuffer_Bind(IndexBuffer* ib);
void IndexBuffer_Unbind();

#endif
