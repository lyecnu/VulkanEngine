#pragma once

#include "vk_common.h"
#include <SDL3/SDL.h>

class VulkanEngine
{
public:
	bool _isInitialized{ false };
	SDL_Window* _window{ nullptr };
	VkExtent2D _windowExtent{ 800, 600 };


    VkInstance _instance{ VK_NULL_HANDLE };
	VkDebugUtilsMessengerEXT _debugMessenger{ VK_NULL_HANDLE };
	VkPhysicalDevice _physicalDevice{ VK_NULL_HANDLE };
	VkDevice _device{ VK_NULL_HANDLE };
	VkSurfaceKHR _surface{ VK_NULL_HANDLE };

public:
	void init();
	void run();

private:
	void initVulkan();
	void initSwapChain();
	void initCommands();
	void initSyncStructures();
};