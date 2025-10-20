#include "IndexBuffer.h"

// IndexBufferCreate creates a Index buffer object with given data and size.
IndexBuffer* IndexBuffer_Create(float* data, uint32_t size) {
    IndexBuffer* ib = malloc(sizeof(IndexBuffer));
    if (!ib) {
        return NULL;
    }
    glGenBuffers(1, &ib->rendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->rendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    printf("Created Index buffer, id: %d.\n", ib->rendererID);
    return ib;
}

// IndexBufferDelete deletes a Index buffer object.
void IndexBuffer_Delete(IndexBuffer* ib) {
    printf("Deleting Index buffer, id: %d.\n", ib->rendererID);
    if (ib) {
        glDeleteBuffers(1, &ib->rendererID);
        free(ib);
        printf("Deleted Index buffer!\n");
    }
}

// IndexBuffer_Bind binds a Index buffer object. The buffer object name is stored in vb->rendererID.
void IndexBuffer_Bind(IndexBuffer* ib) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->rendererID);
}

// IndexBuffer_Unbind unbinds a previously bounded Index buffer object.
void IndexBuffer_Unbind(IndexBuffer* ib) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
