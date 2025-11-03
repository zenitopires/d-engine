#pragma once
#include "GameContext.h"

typedef struct Application {
    GameContext* gameContext;
} Application;

Application* Application_Create(GameContext* gameContext);
void Application_Run(Application* app);
