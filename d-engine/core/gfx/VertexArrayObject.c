#ifndef VERTEX_ARRAY_OBJECT_H
#define VERTEX_ARRAY_OBJECT_H
#include "d-engine/core/gfx/IndexBuffer.h"
#include "d-engine/core/gfx/VertexBuffer.h"
#include "log.h"
#include <glad/glad.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct VertexArrayObject {
    uint32_t rendererID;
} VertexArrayObject;

VertexArrayObject* VertexArrayObject_Create() {
#ifdef DEBUG
    log_debug("Entered VertexArrayObject_Create");
    log_debug("Creating vertex array object!\n");
#endif
    VertexArrayObject* vao = malloc(sizeof(VertexArrayObject));
    if (!vao) {
        log_error("Failed to allocate memory for vertex array object!");
        return nullptr;
    }
    glGenVertexArrays(1, &vao->rendererID);
    glBindVertexArray(vao->rendererID);
#ifdef DEBUG
    log_debug("Created vertex array object, id: %d!\n", vao->rendererID);
#endif
    return vao;
}

void VertexArrayObject_Attach_Buffers(VertexBuffer* vb, IndexBuffer* ib) {
#ifdef DEBUG
    log_debug("Entered VertexArrayObject_Attach_Buffers.");
#endif
    if (ib) {
#ifdef DEBUG
    log_debug("Attaching index buffer to vertex array object.");
#endif
        IndexBuffer_Bind(ib);
    }
#ifdef DEBUG
        log_debug("Attaching vertex buffer to vertex array object.");
#endif
    VertexBuffer_Bind(vb);
}

void VertexArrayObject_Attribute() {
#ifdef DEBUG
    log_debug("Entered VertexArrayObject_Attribute.");
#endif
    // Hardcoded for now until I figure out the best way to handle attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void VertexArrayObject_Delete(VertexArrayObject* vao) {
#ifdef DEBUG
    log_debug("Entered VertexArrayObject_Delete");
#endif
    if (vao) {
#ifdef DEBUG
        log_debug("Deleting vertex array object, id: %d!", vao->rendererID);
#endif
        glDeleteVertexArrays(1, &vao->rendererID);
        // TODO: Need to handle OpenGL errors here.. and well... everywhere else. That's for later!
#ifdef DEBUG
        log_debug("Deleted vertex array object, id: %d!", vao->rendererID);
#endif
        free(vao);
    }
}

void VertexArrayObject_Bind(VertexArrayObject* vao) {
#ifdef DEBUG
    log_debug("Entered VertexArrayObject_Bind");
    log_debug("Binding vertex array object, id: %d", vao->rendererID);
#endif
    glBindVertexArray(vao->rendererID);
}

void VertexArrayObject_Unbind() {
    glBindVertexArray(0);
}

#endif
