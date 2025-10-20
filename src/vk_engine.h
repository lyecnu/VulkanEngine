#pragma once

#include "vk_common.h"

class VulkanEngine
{
public:
	bool _isInitialized{ false };
	int _frameNumber{ 0 };
	bool _isStopRendering{ false };
	VkExtent2D _windowExtent{ 800, 600 };

    VkInstance _instance{ VK_NULL_HANDLE };
	VkDebugUtilsMessengerEXT _debugMessenger{ VK_NULL_HANDLE };
	VkPhysicalDevice _physicalDevice{ VK_NULL_HANDLE };
	VkDevice _device{ VK_NULL_HANDLE };
	VkSurfaceKHR _surface{ VK_NULL_HANDLE };

public:
	static VulkanEngine& Instance();

	void Init();
	void Draw();
	void Cleanup();
	void Run();

private:
	struct SDL_Window* _window{ nullptr };

private:
	VulkanEngine() = default;
	~VulkanEngine() = default;
	VulkanEngine(const VulkanEngine&) = delete;
	VulkanEngine& operator=(const VulkanEngine&) = delete;
	VulkanEngine(VulkanEngine&&) = delete;
	VulkanEngine& operator=(VulkanEngine&&) = delete;

	void InitVulkan();
	void InitSwapChain();
	void InitCommands();
	void InitSyncStructures();
};