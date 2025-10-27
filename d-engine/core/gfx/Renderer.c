#include <stdlib.h>
#include <glad/glad.h>
#include "d-engine/core/gfx/VertexArray.h"
#include "d-engine/core/log/Log.h"
#include "Renderer.h"

static void _initRenderer() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Renderer* Renderer_Create() {
    debug_msg("Entered Renderer_Create");
    Renderer* renderer = malloc(sizeof(Renderer));
    if (!renderer) {
        return nullptr;
    }
    _initRenderer();
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer_Draw(VertexArray* vao) {
    VertexArray_Bind(vao);
    glDrawElements(GL_TRIANGLES, vao->indexCount, GL_UNSIGNED_INT, 0);
    VertexArray_Unbind();
}
