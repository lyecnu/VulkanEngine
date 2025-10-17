add_executable(engine
    main.cpp
    vk_common.h
    vk_engine.h
    vk_engine.cpp
)

set_property(TARGET engine PROPERTY CXX_STANDARD 20)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Vulkan REQUIRED)
target_link_libraries(engine PUBLIC Vulkan::Vulkan glfw)

target_precompile_headers(engine PUBLIC 
    <optional> 
    <vector> 
    <memory>
    <string> 
    <unordered_map> 
)