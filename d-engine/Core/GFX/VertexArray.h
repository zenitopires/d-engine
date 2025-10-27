#pragma once
#include <stdint.h>
#include <glad/glad.h>

// TODO: Maybe move this somewhere else...
typedef struct Data {
    void* vertexData;
    void* indexData;
    uint32_t vertexCount;
    uint32_t indexCount;
    uint32_t shader;
} Data;

// VertexArray represents an OpenGL vertex array object.
typedef struct VertexArray {
    // rendererID is the name of vertex array object.
    uint32_t rendererID;
    // vertexBuffer is the name of vertex buffer object.
    uint32_t vertexBuffer;
    // indexBuffer is the name of vertex buffer object.
    uint32_t indexBuffer;
    // shader is the name of vertex buffer object.
    uint32_t shader;
    // vertexCount is the number of vertices in the vertex data.
    uint32_t vertexCount;
    // indexCount is the number of indices in the index data.
    uint32_t indexCount;
} VertexArray;

// VertexArray_Create creates a vertex array object.
VertexArray* VertexArray_Create(Data* data);
// VertexArray_Attribute defines the data layout for the vertex array object.
void VertexArray_Attribute();
// VertexArray_Delete deletes the provided vertex array object.
void VertexArray_Delete(VertexArray* vao);
// VertexArray_Bind binds the provided vertex array object.
void VertexArray_Bind(VertexArray* vao);
// VertexArray_Unbind unbinds a previously bounded vertex array object.
void VertexArray_Unbind();
