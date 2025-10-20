#include "VertexBuffer.h"

// VertexBufferCreate creates a vertex buffer object with given data and size.
VertexBuffer* VertexBuffer_Create(float* data, uint32_t size) {
    VertexBuffer* vb = malloc(sizeof(VertexBuffer));
    if (!vb) {
        return NULL;
    }
    glGenBuffers(1, &vb->rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, vb->rendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    printf("Created vertex buffer, id: %d.\n", vb->rendererID);
    return vb;
}

// VertexBufferDelete deletes a vertex buffer object.
void VertexBuffer_Delete(VertexBuffer* vb) {
    printf("Deleting vertex buffer, id: %d.\n", vb->rendererID);
    if (vb) {
        glDeleteBuffers(1, &vb->rendererID);
        free(vb);
        printf("Deleted vertex buffer!\n");
    }
}

// VertexBuffer_Bind binds a vertex buffer object. The buffer object name is stored in vb->rendererID.
void VertexBuffer_Bind(VertexBuffer* vb) {
    glBindBuffer(GL_ARRAY_BUFFER, vb->rendererID);
}

// VertexBuffer_Unbind unbinds a previously bounded vertex buffer object.
void VertexBuffer_Unbind(VertexBuffer* vb) {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
