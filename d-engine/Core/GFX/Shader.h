#pragma once
#include <stdint.h>
#include <glad/glad.h>

// ShaderType represents the different types of shaders you can create in OpenGL.
typedef enum ShaderType {
    VertexShader,
    FragmentShader
} ShaderType;

// Shader_Create creates a shader program given a vertex shader source path and a fragment shader source path.
unsigned int Shader_Create(const char* vertexShaderSrc, const char* fragmentShaderSrc);
// Shader_Delete deletes the provided shader program.
void Shader_Delete(unsigned int shader);
// Shader_Bind uses (it's called 'bind' to fit the convention I've got going on) the provided shader program.
void Shader_Bind(unsigned int shader);
// Shader_Unbind unbinds (unuse?) the previously binded (used) shader program.
void Shader_Unbind();
// _shaderCreate is a helper function to open and parse shader files on disk into memory so that they can be used in Shader_Create.
uint32_t _shaderCreate(const char* shaderSrcPath, ShaderType shaderType);
