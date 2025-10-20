#include <stdio.h>
#include "d-engine/core/gfx/VertexBuffer.h"
#include "d-engine/core/os/window/WindowProperties.h"
#include "d-engine/core/os/window/Window.h"

int main()
{
    WindowProps wp = WindowPropsCreate("Zen", 1280, 720, true);
    WindowData* wd = WindowCreate(&wp);
    InitializeWindow(wd);

    bool appRunning = true;

    float vertices[6] = {
         0.0f,  0.5f,  // top vertex
        -0.5f, -0.5f,  // bottom left vertex
         0.5f, -0.5f   // bottom right vertex
    };

    VertexBuffer *vb = VertexBufferCreate(vertices, sizeof(vertices));

    while (appRunning)
    {
        WindowOnUpdate(wd, &appRunning);
    }

    WindowDelete(wd);

    VertexBufferDelete(vb);

    return 0;
}
