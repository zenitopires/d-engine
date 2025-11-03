#include <stdint.h>
#include "d-engine/Core/GFX/VertexArray.h"

typedef struct GameContext {
    void (*OnInit)(void*);
    void (*OnUpdate)(void*, float dt);
    void (*OnRender)(void*);
    void (*OnShutdown)(void*);
    Data* objects;
    void* userData;
} GameContext;
