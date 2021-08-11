#pragma once

#include <GLFW/glfw3.h>

namespace Lava
{
    class Application
    {
    public:
        void Run();

    private:
        void InitWindow();
        void InitVulkan();
        void MainLoop();
        void Cleanup();

    private:
        GLFWwindow *m_Window;
        const uint32_t WINDOW_WIDTH = 800;
        const uint32_t WINDOW_HEIGHT = 600;
    };
}