#include "vk_engine.h"
#include <iostream>
int main()
{
    VulkanEngine& engine = VulkanEngine::Instance();

    engine.Init();
	engine.Run();
	std::cin.get();

    return 0;
}