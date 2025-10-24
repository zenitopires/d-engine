#include <stdlib.h>
#include <glad/glad.h>
#include "d-engine/core/log/Log.h"
#include "IndexBuffer.h"

IndexBuffer* IndexBuffer_Create(unsigned int* data, uint32_t size) {
    debug_msg("Entered IndexBuffer_Create");
    debug_msg("Creating index buffer!");
    IndexBuffer* ib = malloc(sizeof(IndexBuffer));
    if (!ib) {
        debug_msg("Failed to allocate memory for index buffer!");
        return nullptr;
    }
    ib->size = size;
    glGenBuffers(1, &ib->rendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->rendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, ib->size, data, GL_STATIC_DRAW);
    debug_msg("Created index buffer, id: %d!", ib->rendererID);
    return ib;
}

void IndexBuffer_Delete(IndexBuffer* ib) {
    if (ib) {
        debug_msg("Deleting Index buffer, id: %d!", ib->rendererID);
        glDeleteBuffers(1, &ib->rendererID);
        debug_msg("Deleted Index buffer, id: %d!", ib->rendererID);
        free(ib);
    }
}

void IndexBuffer_Bind(IndexBuffer* ib) {
    debug_msg("Entered IndexBuffer_Bind");
    debug_msg("Binding index buffer, id: %d", ib->rendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->rendererID);
}

void IndexBuffer_Unbind() {
    debug_msg("Entered IndexBuffer_Unbind");
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
