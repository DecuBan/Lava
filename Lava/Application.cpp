#include "Application.hpp"
#include "Logger.hpp"

namespace Lava
{
    void Application::InitWindow()
    {
        int glfwStatus = glfwInit();
        LAVA_ASSERT(glfwStatus, "Can't initialize glfw!");

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_Window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Lava - Vulkan window", nullptr, nullptr);
    }

    void Application::InitVulkan()
    {
    }

    void Application::MainLoop()
    {
        while (!glfwWindowShouldClose(m_Window))
        {
            glfwPollEvents();
        }
    }

    void Application::Cleanup()
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Application::Run()
    {
        InitWindow();
        InitVulkan();
        MainLoop();
        Cleanup();
    }
}