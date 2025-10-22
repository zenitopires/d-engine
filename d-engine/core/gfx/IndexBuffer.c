#include "log.h"
#include "IndexBuffer.h"

IndexBuffer* IndexBuffer_Create(unsigned int* data, uint32_t size) {
#ifdef DEBUG
    log_debug("Entered IndexBuffer_Create");
    log_debug("Creating index buffer!");
#endif
    IndexBuffer* ib = malloc(sizeof(IndexBuffer));
    if (!ib) {
#ifdef DEBUG
        log_debug("Failed to allocate memory for index buffer!");
#endif
        return nullptr;
    }
    glGenBuffers(1, &ib->rendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->rendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
#ifdef DEBUG
    log_debug("Created index buffer, id: %d!", ib->rendererID);
#endif
    return ib;
}

void IndexBuffer_Delete(IndexBuffer* ib) {
    if (ib) {
#ifdef DEBUG
        log_debug("Deleting Index buffer, id: %d!", ib->rendererID);
#endif
        glDeleteBuffers(1, &ib->rendererID);
#ifdef DEBUG
        log_debug("Deleted Index buffer, id: %d!", ib->rendererID);
#endif
        free(ib);
    }
}

void IndexBuffer_Bind(IndexBuffer* ib) {
#ifdef DEBUG
    log_debug("Entered IndexBuffer_Bind");
    log_debug("Binding index buffer, id: %d", ib->rendererID);
#endif
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->rendererID);
}

void IndexBuffer_Unbind() {
#ifdef DEBUG
    log_debug("Entered IndexBuffer_Unbind");
#endif
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
