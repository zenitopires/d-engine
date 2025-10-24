#include "Renderer.h"
#include "d-engine/core/gfx/Shader.h"
#include "d-engine/core/gfx/VertexArrayObject.h"
#include "d-engine/core/log/log.h"
#include <glad/glad.h>
#include <stdlib.h>

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

void Renderer_Draw(VertexArrayObject* vao,  Shader* shader) {
    VertexArrayObject_Bind(vao);
    Shader_Bind(shader);
    glDrawElements(GL_TRIANGLES, vao->indicesCount, GL_UNSIGNED_INT, 0);
    VertexArrayObject_Unbind();
    Shader_Unbind();
}
