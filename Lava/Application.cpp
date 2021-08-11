#include "Application.hpp"
#include "Logger.hpp"

#include <vector>

namespace Lava
{
    void Application::InitWindow()
    {
        m_Window = new Window(1280, 720, "Lava - Vulkan window");
    }

    void Application::InitVulkan()
    {
        CreateVulkanInstance();

        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

        LAVA_TRACE("{0} extensions available:", extensionCount);

        for (auto &extension : extensions)
        {
            LAVA_TRACE("\t{0}", extension.extensionName);
        }
    }

    void Application::CreateVulkanInstance()
    {
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Bye triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t glfwExtensionCount = 0;
        const char **glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;

        createInfo.enabledLayerCount = 0;

        VkResult result = vkCreateInstance(&createInfo, nullptr, &m_VkInstance);
        if (result != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create instance!");
        }
    }

    void Application::MainLoop()
    {
        while (!m_Window->IsClosed())
        {
            glfwPollEvents();
        }
    }

    void Application::Cleanup()
    {
        vkDestroyInstance(m_VkInstance, nullptr);
        delete m_Window;
    }

    void Application::Run()
    {
        InitWindow();
        InitVulkan();
        MainLoop();
        Cleanup();
    }
}