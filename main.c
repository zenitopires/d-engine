#include <stdio.h>
#include "d-engine/core/gfx/IndexBuffer.h"
#include "d-engine/core/os/window/WindowProperties.h"
#include "d-engine/core/os/window/Window.h"
#include "d-engine/core/gfx/VertexBuffer.h"
#include "d-engine/core/gfx/VertexArrayObject.h"

int main()
{
    WindowProps wp = WindowPropsCreate("Zen", 1280, 720, true);
    WindowData* wd = WindowCreate(&wp);
    InitializeWindow(wd);

    bool appRunning = true;

    float vertices[] = {
			 0.5f,  0.5f, 0.0f,  // top right
			 0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f,  // top left
			 0.3f,  0.2f, 0.25f
		};
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	VertexArrayObject* vao = VertexArrayObject_Create();

    VertexBuffer* vb = VertexBuffer_Create(vertices, sizeof(vertices));
    IndexBuffer* ib = IndexBuffer_Create(indices, sizeof(indices));

    VertexArrayObject_Attach_Buffers(vb, ib);

    while (appRunning)
    {
        WindowOnUpdate(wd, &appRunning);
    }

    WindowDelete(wd);
    VertexBuffer_Delete(vb);
    IndexBuffer_Delete(ib);
    VertexArrayObject_Delete(vao);

    return 0;
}
