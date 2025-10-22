#include "log.h"
#include "VertexBuffer.h"
#ifdef DEBUG
#include "d-engine/core/debug/debug.h"
#endif

VertexBuffer* VertexBuffer_Create(float* data, uint32_t size) {
#ifdef DEBUG
    log_debug("Entered VertexBuffer_Create");
    char buf[512];
    floatArrayToString(data, size / sizeof(float), buf, sizeof(buf));
    log_debug("Creating vertex buffer with data=%s, size=%d", buf, size);
#endif
    VertexBuffer* vb = malloc(sizeof(VertexBuffer));
    if (!vb) {
        log_error("Failed to allocate memory for VertexBuffer!");
        return nullptr;
    }
    glGenBuffers(1, &vb->rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, vb->rendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
#ifdef DEBUG
    log_debug("Created vertex buffer, id: %d.", vb->rendererID);
#endif
    return vb;
}

void VertexBuffer_Delete(VertexBuffer* vb) {
#ifdef DEBUG
    log_debug("Entered VertexBuffer_Delete");
#endif
    if (vb) {
#ifdef DEBUG
    log_debug("Deleting vertex buffer, id: %d!", vb->rendererID);
#endif
    glDeleteBuffers(1, &vb->rendererID);
    free(vb);
#ifdef DEBUG
    log_debug("Deleted vertex buffer!");
#endif
    }
}

void VertexBuffer_Bind(VertexBuffer* vb) {
#ifdef DEBUG
    log_debug("Entered VertexBuffer_Bind");
#endif
    glBindBuffer(GL_ARRAY_BUFFER, vb->rendererID);
}

void VertexBuffer_Unbind() {
#ifdef DEBUG
    log_debug("Entered VertexBuffer_Unbind");
#endif
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
