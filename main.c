#include <stdlib.h>
#include "d-engine/Core/Application/Application.h"

void GameUpdate(void*, float dt){

}

int main()
{
    // Maybe turn this pattern of parsing data into a scene reader??
    float vertices[] = {
         0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 0.5f, 0.5f, 0.5f
    };

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	Data* data = malloc(sizeof(Data));
    data->vertexData = vertices;
    data->indexData = indices;
    data->vertexCount = sizeof(vertices) / sizeof(float);
    data->indexCount = sizeof(indices) / sizeof(unsigned int);

    GameContext* gameContext = malloc(sizeof(GameContext));
    void* data_t = nullptr;
    // gameContext->OnUpdate = GameUpdate;
    gameContext->objects = data;
    Application* app = Application_Create(gameContext);
    Application_Run(app);
    return 0;
}
