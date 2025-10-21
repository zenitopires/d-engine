#include "VertexBuffer.h"

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

void VertexBuffer_Delete(VertexBuffer* vb) {
    if (vb) {
        printf("Deleting vertex buffer, id: %d!\n", vb->rendererID);
        glDeleteBuffers(1, &vb->rendererID);
        free(vb);
        printf("Deleted vertex buffer!\n");
    }
}

void VertexBuffer_Bind(VertexBuffer* vb) {
    glBindBuffer(GL_ARRAY_BUFFER, vb->rendererID);
}

void VertexBuffer_Unbind(VertexBuffer* vb) {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
