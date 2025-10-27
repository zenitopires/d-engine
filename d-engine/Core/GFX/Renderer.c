#include <stdlib.h>
#include <glad/glad.h>
#include "d-engine/Core/GFX/Shader.h"
#include "d-engine/Core/GFX/VertexArray.h"
#include "d-engine/Core/Log/Log.h"
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
    renderer->capacity = 5;
    renderer->size = 0;
    renderer->renderables = malloc(sizeof(Renderable) * renderer->capacity);
    _initRenderer();
    return renderer;
}

void Renderer_Delete(Renderer* renderer) {
    if (!renderer) {
        error_msg("Cannot delete uninitialized renderer!");
        return;
    }
    if (renderer->renderables) {
        free(renderer->renderables);
    }
    free(renderer);
}

void Renderer_Clear(vec4 color) {
    glClearColor(color[0], color[1], color[2], color[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer_Draw(Renderer* renderer) {
    for (int i = 0; i < renderer->size; i++) {
        VertexArray_Bind(renderer->renderables[i].vao);
        glUniformMatrix4fv(Shader_Get_Uniform(renderer->renderables[i].vao->shader, "transform"), 1, GL_FALSE, renderer->renderables[i].transform[0]);
        glUniform3fv(Shader_Get_Uniform(renderer->renderables[i].vao->shader, "position"), 1, renderer->renderables[i].position);
        glDrawElements(GL_TRIANGLES, renderer->renderables[i].vao->indexCount, GL_UNSIGNED_INT, 0);
        VertexArray_Unbind();
    }
}

void Renderer_Submit(Renderer* renderer, Renderable* renderable) {
    if (renderer->size >= renderer->capacity) {
        renderer->capacity *= 2;
        renderer->renderables = realloc(renderer->renderables,
                                        sizeof(Renderable) * renderer->capacity);
    }
    renderer->renderables[renderer->size] = *renderable;
    renderer->size++;
}
