#pragma once

#include "Window.hpp"
#include <vector>

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

        void CreateVulkanInstance();
        std::vector<const char *> GetRequiredExtensions();
        bool CheckValidationLayerSupport();
        void SetupDebugMessenger();
        void PickPhysicalDevice();

        bool IsDeviceSuitable(VkPhysicalDevice device);

        static VKAPI_ATTR VkBool32 VKAPI_CALL VkDebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                              VkDebugUtilsMessageTypeFlagsEXT messageType,
                                                              const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
                                                              void *pUserData);

        VkResult CreateDebugUtilsMessengerEXT(VkInstance instance,
                                              const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
                                              const VkAllocationCallbacks *pAllocator,
                                              VkDebugUtilsMessengerEXT *pDebugMessenger);

        void DestroyDebugUtilsMessengerEXT(VkInstance instance,
                                           VkDebugUtilsMessengerEXT debugMessenger,
                                           const VkAllocationCallbacks *pAllocator);

        void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);

    private:
        Window *m_Window;

        VkInstance m_VkInstance;

        VkPhysicalDevice m_VkPhysicalDevice = VK_NULL_HANDLE;

        const std::vector<const char *> m_VkValidationLayers = {"VK_LAYER_KHRONOS_validation"};
        VkDebugUtilsMessengerEXT m_VkDebugMessenger;

#ifdef LAVA_DEBUG
        const bool m_VkEnableValidationLayers = true;
#else
        const bool m_VkEnableValidationLayers = false;
#endif
    };
}