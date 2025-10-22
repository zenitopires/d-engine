#include "Shader.h"
#include <glad/glad.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

Shader* Shader_Create(const char* vertexShaderSrcPath, const char* fragmentShaderSrcPath) {
    uint32_t vertexShader = _shaderCreate(vertexShaderSrcPath, VertexShader);
    uint32_t fragmentShader = _shaderCreate(fragmentShaderSrcPath, FragmentShader);
    Shader* shader = malloc(sizeof(Shader));
    if (!shader) {
        return NULL;
    }
    shader->rendererID = glCreateProgram();
    glAttachShader(shader->rendererID, vertexShader);
    glAttachShader(shader->rendererID, fragmentShader);
    glLinkProgram(shader->rendererID);
    GLint program_linked;
    glGetProgramiv(shader->rendererID, GL_LINK_STATUS, &program_linked);
    if (program_linked != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetProgramInfoLog(shader->rendererID, 1024, &log_length, message);
        printf("Error: %s", message);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shader;
}

void Shader_Delete(Shader* shader) {
    printf("Deleting shader program, id: %d!\n", shader->rendererID);
    glDeleteProgram(shader->rendererID);
    printf("Deleted shader program, id: %d!\n", shader->rendererID);
    free(shader);
}

void Shader_Bind(Shader* shader) {
    glUseProgram(shader->rendererID);
}

void Shader_Unbind() {
    glUseProgram(0);
}

uint32_t _shaderCreate(const char* shaderSrcPath, enum ShaderType shaderType) {
    FILE* file = fopen(shaderSrcPath, "rb");
    if (!file) {
        printf("Failed to open shader file: %s\n", shaderSrcPath);
        return 0;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);
    char* source = malloc(length + 1);
    if (!source) {
        printf("Failed to allocate memory for shader: %s\n", shaderSrcPath);
        fclose(file);
        return 0;
    }
    fread(source, 1, length, file);
    source[length] = '\0';
    fclose(file);

    uint32_t shader = 0;
    switch (shaderType)
    {
        case VertexShader:
            shader = glCreateShader(GL_VERTEX_SHADER);
            break;
        case FragmentShader:
            shader = glCreateShader(GL_FRAGMENT_SHADER);
            break;
        default:
            printf("Shader type not supported!\n");
    }
    glShaderSource(shader, 1, (const char**)&source, NULL);
	glCompileShader(shader);
	free(source);
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		// std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		printf("Error: %s", infoLog);
		return -1;
	}
	return shader;
}
