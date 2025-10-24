#include <stdlib.h>
#include <glad/glad.h>
#include "d-engine/core/gfx/Shader.h"
#include "d-engine/core/gfx/VertexArray.h"
#include "d-engine/core/log/Log.h"
#include "Renderer.h"

Renderer* Renderer_Create() {
    debug_msg("Entered Renderer_Create");
    Renderer* renderer = malloc(sizeof(Renderer));
    if (!renderer) {
        return nullptr;
    }
    return renderer;
}

void Renderer_Delete(Renderer* renderer) {
    if (!renderer) {
        error_msg("Cannot delete uninitialized renderer!");
        return;
    }
    free(renderer);
}

void Renderer_Clear(vec4 color) {
    glClearColor(color[0], color[1], color[2], color[3]);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer_Draw(VertexArray* vao,  Shader* shader) {
    VertexArray_Bind(vao);
    Shader_Bind(shader);
    glDrawElements(GL_TRIANGLES, vao->indicesCount, GL_UNSIGNED_INT, 0);
    VertexArray_Unbind();
    Shader_Unbind();
}
