#include "VertexBuffer.h"
#include "d-engine/core/log/log.h"
#include <glad/glad.h>
#include <stdlib.h>

VertexBuffer* VertexBuffer_Create(float* data, uint32_t size) {
    debug_msg("Entered VertexBuffer_Create");
#ifdef DEBUG
    char buf[512];
    floatArrayToString(data, size / sizeof(float), buf, sizeof(buf));
#endif
    debug_msg("Creating vertex buffer with data=%s, size=%d", buf, size);
    VertexBuffer* vb = malloc(sizeof(VertexBuffer));
    if (!vb) {
        error_msg("Failed to allocate memory for VertexBuffer!");
        return nullptr;
    }
    glGenBuffers(1, &vb->rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, vb->rendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    debug_msg("Created vertex buffer, id: %d.", vb->rendererID);
    return vb;
}

void VertexBuffer_Delete(VertexBuffer* vb) {
    debug_msg("Entered VertexBuffer_Delete");
    if (vb) {
        debug_msg("Deleting vertex buffer, id: %d!", vb->rendererID);
        glDeleteBuffers(1, &vb->rendererID);
        free(vb);
        debug_msg("Deleted vertex buffer!");
    }
}

void VertexBuffer_Bind(VertexBuffer* vb) {
    debug_msg("Entered VertexBuffer_Bind");
    glBindBuffer(GL_ARRAY_BUFFER, vb->rendererID);
}

void VertexBuffer_Unbind() {
    debug_msg("Entered VertexBuffer_Unbind");
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
