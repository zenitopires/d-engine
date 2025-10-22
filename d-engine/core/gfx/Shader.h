#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

enum ShaderType {
    VertexShader,
    FragmentShader
};

typedef struct Shader {
    uint32_t rendererID;
} Shader;

Shader* Shader_Create(const char* vertexShaderSrc, const char* fragmentShaderSrc);
void Shader_Delete(Shader* shader);
void Shader_Bind(Shader* shader);
void Shader_Unbind();
uint32_t _shaderCreate(const char* shaderSrcPath, enum ShaderType shaderType);

#endif
