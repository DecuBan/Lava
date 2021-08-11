#pragma once

#include <GLFW/glfw3.h>
#include <string>

namespace Lava
{
    class Window
    {
    public:
        Window(int width, int height, std::string title);
        ~Window();

        inline int GetWidth() const { return m_Width; }
        inline int GetHeight() const { return m_Height; }
        inline std::string GetTitle() const { return m_Title; }
        inline GLFWwindow *GetNativeWindow() const { return m_Window; }

        inline bool IsClosed() const { return glfwWindowShouldClose(m_Window); }

        static void InitWindowManager();
        static void TerminateWindowManager();

    private:
        int m_Width;
        int m_Height;
        std::string m_Title;
        GLFWwindow *m_Window;
    };
}