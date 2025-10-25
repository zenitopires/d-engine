#include <stdlib.h>
#include <glad/glad.h>
#include "d-engine/core/log/Log.h"
#include "Buffer.h"

Buffer* Buffer_Create(unsigned int target, const void* data, uint32_t size) {
    debug_msg("Entered Buffer_Create");
#ifdef DEBUG
    char buf[512];
    switch(target)
    {
        case GL_ARRAY_BUFFER:
            floatArrayToString((const float*)data, size / sizeof(float), buf, sizeof(buf));
            break;
        case GL_ELEMENT_ARRAY_BUFFER:
            intArrayToString((const int*)data, size / sizeof(int), buf, sizeof(buf));
            break;
        default:
            debug_msg("Unknown target type!");
    }
#endif
    debug_msg("Creating buffer with data=%s, size=%d", buf, size);
    Buffer* buffer = malloc(sizeof(Buffer));
    if (!buffer) {
        error_msg("Failed to allocate memory for Buffer!");
        return nullptr;
    }
    buffer->target = target;
    buffer->size = size;
    glGenBuffers(1, &buffer->rendererID);
    glBindBuffer(buffer->target, buffer->rendererID);
    glBufferData(buffer->target, buffer->size, data, GL_STATIC_DRAW);
    debug_msg("Created buffer, id: %d.", buffer->rendererID);
    return buffer;
}

void Buffer_Delete(Buffer* buffer) {
    debug_msg("Entered Buffer_Delete");
    if (buffer) {
        debug_msg("Deleting buffer, id: %d!", buffer->rendererID);
        glDeleteBuffers(1, &buffer->rendererID);
        free(buffer);
        debug_msg("Deleted buffer!");
    }
}

void Buffer_Bind(Buffer* buffer) {
    debug_msg("Entered Buffer_Bind");
    glBindBuffer(buffer->target, buffer->rendererID);
}

void Buffer_Unbind(Buffer* buffer) {
    debug_msg("Entered Buffer_Unbind");
    glBindBuffer(buffer->target, 0);
}
