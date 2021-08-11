#pragma once

#include "Window.hpp"

namespace Lava
{
    class Application
    {
    public:
        void Run();

    private:
        void InitWindow();
        void InitVulkan();
        void CreateVulkanInstance();
        void MainLoop();
        void Cleanup();

    private:
        Window *m_Window;

        VkInstance m_VkInstance;
    };
}