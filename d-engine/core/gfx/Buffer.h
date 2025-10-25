#pragma once
#include <stdint.h>

// Buffer represents an OpenGL buffer object.
typedef struct Buffer {
    // rendererID is the name of the buffer object.
    uint32_t rendererID;
    uint32_t size;
    unsigned int target;
} Buffer;

// Buffer_Create creates a buffer object with the provided data and size.
Buffer* Buffer_Create(unsigned int targert, const void* data, uint32_t size);
// Buffer_Delete deletes the provided buffer object.
void Buffer_Delete(Buffer* buffer);
// Buffer_Bind binds a buffer object.
void Buffer_Bind(Buffer* buffer);
// Buffer_Unbind unbinds a previously bounded buffer object.
void Buffer_Unbind(Buffer* buffer);
