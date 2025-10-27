#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include "d-engine/Core/Log/Log.h"
#include "Shader.h"

unsigned int Shader_Create(const char* vertexShaderSrcPath, const char* fragmentShaderSrcPath) {
    debug_msg("Entered Shader_Create");
    uint32_t vertexShader = _shaderCreate(vertexShaderSrcPath, VertexShader);
    uint32_t fragmentShader = _shaderCreate(fragmentShaderSrcPath, FragmentShader);
    unsigned int shader = glCreateProgram();
    glAttachShader(shader, vertexShader);
    glAttachShader(shader, fragmentShader);
    glLinkProgram(shader);
    GLint program_linked;
    glGetProgramiv(shader, GL_LINK_STATUS, &program_linked);
    if (program_linked != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetProgramInfoLog(shader, 1024, &log_length, message);
        error_msg("Error: %s", message);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    debug_msg("Created shader program, id: %d", shader);
    return shader;
}

void Shader_Delete(unsigned int shader) {
    debug_msg("Entered Shader_Delete");
    debug_msg("Deleting shader program, id: %d!", shader);
    glDeleteProgram(shader);
    debug_msg("Deleted shader program, id: %d!", shader);
}

void Shader_Bind(unsigned int shader) {
    debug_msg("Entered Shader_Bind");
    debug_msg("Binding shader program, id: %d", shader);
    glUseProgram(shader);
}

void Shader_Unbind() {
    debug_msg("Entered Shader_Unbind");
    debug_msg("Unbinding previously binded shader!");
    glUseProgram(0);
}

uint32_t _shaderCreate(const char* shaderSrcPath, ShaderType shaderType) {
    debug_msg("Entered _shaderCreate");
    debug_msg("Attempting to open shader file at %s!", shaderSrcPath);
    FILE* file = fopen(shaderSrcPath, "rb");
    if (!file) {
        log_error("Failed to open shader file: %s", shaderSrcPath);
        return 0;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);
    char* source = malloc(length + 1);
    if (!source) {
        log_error("Failed to allocate memory for shader: %s", shaderSrcPath);
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
            log_error("Shader type not supported!");
            // TODO: I think I want to return something other than 0 when this function errors.
            return 0;
    }
    glShaderSource(shader, 1, (const char**)&source, nullptr);
	glCompileShader(shader);
	free(source);
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		// std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		error_msg("Error: %s", infoLog);
		return 0;
	}
	return shader;
}
