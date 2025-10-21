#include "vk_engine.h"

#include <thread>
#include <chrono>

#include "SDL3/SDL.h"
#include "SDL3/SDL_vulkan.h"
#include "VkBootstrap.h"

#ifdef _DEBUG
static constexpr bool enableValidationLayers = true;
#else
static constexpr bool enableValidationLayers = false;
#endif // DEBUG

static const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};

VulkanEngine& VulkanEngine::Instance()
{
	static VulkanEngine instance;
	return instance;
}

void VulkanEngine::Init()
{
	if (_isInitialized) return;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_WindowFlags windowFlags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);
	_window = SDL_CreateWindow(
		"Vulkan Engine",
		_windowExtent.width,
		_windowExtent.height,
		windowFlags
	);

	_isInitialized = true;

	InitVulkan();
	InitSwapChain();
	InitCommands();
	InitSyncStructures();
}

void VulkanEngine::Cleanup()
{
	if (!_isInitialized) return;
}

void VulkanEngine::Draw()
{
}


void VulkanEngine::Run()
{
	SDL_Event e;
	bool bQuit = false;

	while (!bQuit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_EVENT_QUIT)
			{
				bQuit = true;
			}
			if (e.type == SDL_EVENT_WINDOW_MINIMIZED)
			{
				_isStopRendering = true;
			}
			if (e.type == SDL_EVENT_WINDOW_RESTORED)
			{
				_isStopRendering = false;
			}
		}

		if (_isStopRendering)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			continue;
		}
		Draw();
	}
}

void VulkanEngine::InitVulkan()
{
	vkb::InstanceBuilder instanceBuilder;
	auto vkbInstance = instanceBuilder.set_app_name("Vulkan Engine")
		.request_validation_layers(enableValidationLayers)
		.use_default_debug_messenger()
		.require_api_version(VK_VERSION_1_3)
		.build()
		.value();

	_instance = vkbInstance.instance;
	_debugMessenger = vkbInstance.debug_messenger;

	SDL_Vulkan_CreateSurface(_window, _instance, nullptr, &_surface);

	VkPhysicalDeviceVulkan13Features features13{ .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES };
	features13.dynamicRendering = true;
	features13.synchronization2 = true;

	VkPhysicalDeviceVulkan12Features features12{ .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES };
	features12.bufferDeviceAddress = true;
	features12.descriptorIndexing = true;

	vkb::PhysicalDeviceSelector selector{ vkbInstance };
	vkb::PhysicalDevice physicalDevice = selector.set_minimum_version(1,3)
		.set_required_features_13(features13)
		.set_required_features_12(features12)
		.set_surface(_surface)
		.select()
		.value();

	vkb::DeviceBuilder deviceBuilder{ physicalDevice };
	vkb::Device vkbDevice = deviceBuilder.build().value();

	_device = vkbDevice.device;
	_physicalDevice = physicalDevice.physical_device;
}

void VulkanEngine::InitSwapChain()
{
	// Create swap chain
	// Create image views for swap chain images
	// Create render pass
	// Create framebuffers for each swap chain image view
}

void VulkanEngine::CreateSwapChain(uint32_t width, uint32_t height)
{
	// Create or recreate the swap chain with given width and height
}

void VulkanEngine::InitCommands()
{
	// Create command pool
	// Allocate command buffers
}

void VulkanEngine::InitSyncStructures()
{
	// Create semaphores and fences for synchronization
}
