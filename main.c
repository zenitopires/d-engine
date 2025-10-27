#include "d-engine/Core/Application/Application.h"

int main()
{
    Application* app = Application_Create();
    Application_Run(app);
    return 0;
}
