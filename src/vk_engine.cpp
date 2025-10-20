#include "vk_engine.h"

#include <thread>
#include <chrono>

#include "SDL3/SDL.h"
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
	vkb::InstanceBuilder builder;
	auto instanceResult = builder.set_app_name("Vulkan Engine")
		.request_validation_layers(enableValidationLayers)
		.require_api_version(VK_VERSION_1_3)
		.build();

	vkb::Instance vkbInstance = instanceResult.value();
}

void VulkanEngine::InitSwapChain()
{
	// Create swap chain
	// Create image views for swap chain images
	// Create render pass
	// Create framebuffers for each swap chain image view
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
