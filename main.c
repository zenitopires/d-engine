#include "d-engine/core/application/Application.h"

int main()
{
    Application* app = Application_Create();
    Application_Run(app);
    return 0;
}
