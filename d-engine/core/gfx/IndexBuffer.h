#pragma once
#include <stdint.h>

// IndexBuffer represents an OpenGL index buffer object.
typedef struct IndexBuffer {
    // rendererID is the name of the index buffer object.
    uint32_t rendererID;
} IndexBuffer;

// IndexBuffer_Create creates an index buffer object with the provided data and size.
IndexBuffer* IndexBuffer_Create(unsigned int* data, uint32_t size);
// IndexBuffer_Delete deletes the provided index buffer object.
void IndexBuffer_Delete(IndexBuffer* ib);
// IndexBuffer_Bind binds the provided index buffer object.
void IndexBuffer_Bind(IndexBuffer* ib);
// IndexBuffer_Unbind unbinds a previously bounded index buffer object.
void IndexBuffer_Unbind(void);
