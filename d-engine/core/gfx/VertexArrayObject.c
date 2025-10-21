#ifndef VERTEX_ARRAY_OBJECT_H
#define VERTEX_ARRAY_OBJECT_H
#include "d-engine/core/gfx/IndexBuffer.h"
#include "d-engine/core/gfx/VertexBuffer.h"
#include <glad/glad.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct VertexArrayObject {
    uint32_t rendererID;
} VertexArrayObject;

VertexArrayObject* VertexArrayObject_Create() {
    printf("Creating vertex array object!\n");
    VertexArrayObject* vao = malloc(sizeof(VertexArrayObject));
    if (!vao) {
        return NULL;
    }
    glGenVertexArrays(1, &vao->rendererID);
    glBindVertexArray(vao->rendererID);
    printf("Created vertex array object, id: %d!\n", vao->rendererID);
    return vao;
}

void VertexArrayObject_Attach_Buffers(VertexBuffer* vb, IndexBuffer* ib) {
    if (ib) {
        IndexBuffer_Bind(ib);
    }
    VertexBuffer_Bind(vb);
}

void VertexArrayObject_Attribute() {
    // Hardcoded for now until I figure out the best way to handle attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void VertexArrayObject_Delete(VertexArrayObject* vao) {
    if (vao) {
        printf("Deleting vertex array object, id: %d!\n", vao->rendererID);
        glDeleteVertexArrays(1, &vao->rendererID);
        // TODO: Need to handle OpenGL errors here.. and well... everywhere else. That's for later!
        printf("Deleted vertex array object, id: %d!\n", vao->rendererID);
        free(vao);
    }
}

void VertexArrayObject_Bind(VertexArrayObject* vao) {
    glBindVertexArray(vao->rendererID);
}

void VertexArrayObject_Unbind(VertexArrayObject* vao) {
    glBindVertexArray(0);
}

#endif
