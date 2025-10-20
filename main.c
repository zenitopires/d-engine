#include <stdio.h>
#include "d-engine/core/os/window/WindowProperties.h"
#include "d-engine/core/os/window/Window.h"

int main()
{
    WindowProps wp = WindowPropsCreate("Zen", 1280, 720, true);
    WindowData* wd = WindowCreate(&wp);
    InitializeWindow(wd);

    bool appRunning = true;

    while (appRunning)
    {
        WindowOnUpdate(wd, &appRunning);
    }

    WindowDelete(wd);

    return 0;
}
