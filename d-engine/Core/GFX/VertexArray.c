#include <stdint.h>
#include <stdlib.h>
#include <glad/glad.h>
#include "d-engine/Core/GFX/VertexArray.h"
#include "d-engine/Core/GFX/Shader.h"
#include "d-engine/Core/Log/Log.h"
#include <SDL3/SDL.h>

VertexArray* VertexArray_Create(Data* data) {
    debug_msg("Entered VertexArray_Create");
    debug_msg("Creating vertex array object!\n");
    VertexArray* vao = malloc(sizeof(VertexArray));
    unsigned int shader = Shader_Create("assets/shaders/defaults/vertex.vert",
	    "assets/shaders/defaults/fragment.frag");
    vao->shader = shader;
    if (!vao) {
        log_error("Failed to allocate memory for vertex array object!");
        return nullptr;
    }
    vao->vertexCount = data->vertexCount;
    vao->indexCount = data->indexCount;
    // Create vertex arrays, buffers
    glGenVertexArrays(1, &vao->rendererID);
    glGenBuffers(1, &vao->vertexBuffer);
    glGenBuffers(1, &vao->indexBuffer);
    // Switch context to vao and associate buffers and their data with it
    glBindVertexArray(vao->rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, vao->vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vao->vertexCount * sizeof(float), (const float*)data->vertexData, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vao->indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, vao->indexCount * sizeof(unsigned int), (const unsigned int*)data->indexData, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
    debug_msg("Created vertex array object, id: %d!\n", vao->rendererID);
    glBindVertexArray(0);
    glUseProgram(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    return vao;
}

void VertexArray_Attribute() {
    debug_msg("Entered VertexArray_Attribute.");
    // Hardcoded for now until I figure out the best way to handle attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void VertexArray_Delete(VertexArray* vao) {
    debug_msg("Entered VertexArray_Delete");
    if (vao) {
        debug_msg("Deleting vertex array object, id: %d!", vao->rendererID);
        glDeleteVertexArrays(1, &vao->rendererID);
        glDeleteProgram(vao->shader);
        // TODO: Need to handle OpenGL errors here.. and well... everywhere else. That's for later!
        debug_msg("Deleted vertex array object, id: %d!", vao->rendererID);
        free(vao);
    }
}

void VertexArray_Bind(VertexArray* vao) {
    debug_msg("Entered VertexArray_Bind");
    debug_msg("Binding vertex array object, id: %d", vao->rendererID);
    glUseProgram(vao->shader);
    glBindVertexArray(vao->rendererID);
}

void VertexArray_Unbind() {
    glBindVertexArray(0);
    glUseProgram(0);
}
