#include "Window.hpp"
#include "Logger.hpp"

namespace Lava
{
    Window::Window(int width, int height, std::string title)
        : m_Width(width), m_Height(height), m_Title(title)
    {
        m_Window = glfwCreateWindow(m_Width, m_Height, "Lava - Vulkan window", nullptr, nullptr);
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_Window);
    }

    void Window::InitWindowManager()
    {
        int glfwStatus = glfwInit();
        LAVA_ASSERT(glfwStatus, "Can't initialize glfw!");

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    }

    void Window::TerminateWindowManager()
    {
        glfwTerminate();
    }
}