#include "vk_engine.h"
#include <stdexcept>

#ifdef _DEBUG
static constexpr bool enableValidationLayers = true;
#else
static constexpr bool enableValidationLayers = false;
#endif // DEBUG

static const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};

void VulkanEngine::init()
{
	initWindow();
	initVulkan();
	initSwapChain();
	initCommands();
	initSyncStructures();

	_isInitialized = true;
}

void VulkanEngine::initWindow()
{
	// Initialize GLFW window
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	_window = glfwCreateWindow(_windowExtent.width, _windowExtent.height, "Vulkan Engine", nullptr, nullptr);
}

void VulkanEngine::initVulkan()
{
	// 1. Create Vulkan instance
	VkApplicationInfo applicationInfo{};
	applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	applicationInfo.pNext = nullptr;
	applicationInfo.pApplicationName = "Vulkan Engine";
	applicationInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	applicationInfo.pEngineName = "No Engine";
	applicationInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	applicationInfo.apiVersion = VK_API_VERSION_1_3;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	VkInstanceCreateInfo instanceInfo{};
	instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceInfo.pNext = nullptr;
	instanceInfo.flags = 0;
	instanceInfo.pApplicationInfo = &applicationInfo;
	instanceInfo.enabledLayerCount = validationLayers.size();
	instanceInfo.ppEnabledLayerNames = validationLayers.data();
	instanceInfo.enabledExtensionCount = glfwExtensionCount;
	instanceInfo.ppEnabledExtensionNames = glfwExtensions;

	if (vkCreateInstance(&instanceInfo, nullptr, &_instance) != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create Vulkan instance.");
	}

	// 2. Setup debug messenger
	
	// Select physical device
	// Create logical device and retrieve queues
	// Create surface for rendering
}

void VulkanEngine::initSwapChain()
{
	// Create swap chain
	// Create image views for swap chain images
	// Create render pass
	// Create framebuffers for each swap chain image view
}

void VulkanEngine::initCommands()
{
	// Create command pool
	// Allocate command buffers
}

void VulkanEngine::initSyncStructures()
{
	// Create semaphores and fences for synchronization
}

void VulkanEngine::run()
{
	while (true)
	{
		// Main loop
	}
}