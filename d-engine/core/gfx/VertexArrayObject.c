#include "d-engine/core/gfx/VertexArrayObject.h"
#include "d-engine/core/gfx/IndexBuffer.h"
#include "d-engine/core/gfx/VertexBuffer.h"
#include "d-engine/core/log/log.h"
#include <glad/glad.h>
#include <stdint.h>
#include <stdlib.h>

VertexArrayObject* VertexArrayObject_Create() {
    debug_msg("Entered VertexArrayObject_Create");
    debug_msg("Creating vertex array object!\n");
    VertexArrayObject* vao = malloc(sizeof(VertexArrayObject));
    if (!vao) {
        log_error("Failed to allocate memory for vertex array object!");
        return nullptr;
    }
    vao->indicesCount = 0;
    glGenVertexArrays(1, &vao->rendererID);
    glBindVertexArray(vao->rendererID);
    debug_msg("Created vertex array object, id: %d!\n", vao->rendererID);
    return vao;
}

void VertexArrayObject_Attach_Buffers(VertexArrayObject* vao, VertexBuffer* vb, IndexBuffer* ib) {
    debug_msg("Entered VertexArrayObject_Attach_Buffers.");
    if (ib) {
    debug_msg("Attaching index buffer to vertex array object.");
        IndexBuffer_Bind(ib);
        vao->indicesCount = ib->size;
    }
        debug_msg("Attaching vertex buffer to vertex array object.");
    VertexBuffer_Bind(vb);
}

void VertexArrayObject_Attribute() {
    debug_msg("Entered VertexArrayObject_Attribute.");
    // Hardcoded for now until I figure out the best way to handle attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void VertexArrayObject_Delete(VertexArrayObject* vao) {
    debug_msg("Entered VertexArrayObject_Delete");
    if (vao) {
        debug_msg("Deleting vertex array object, id: %d!", vao->rendererID);
        glDeleteVertexArrays(1, &vao->rendererID);
        // TODO: Need to handle OpenGL errors here.. and well... everywhere else. That's for later!
        debug_msg("Deleted vertex array object, id: %d!", vao->rendererID);
        free(vao);
    }
}

void VertexArrayObject_Bind(VertexArrayObject* vao) {
    debug_msg("Entered VertexArrayObject_Bind");
    debug_msg("Binding vertex array object, id: %d", vao->rendererID);
    glBindVertexArray(vao->rendererID);
}

void VertexArrayObject_Unbind() {
    glBindVertexArray(0);
}
