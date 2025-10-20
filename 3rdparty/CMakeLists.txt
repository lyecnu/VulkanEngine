find_package(Vulkan REQUIRED)

#vk-bootstrap
add_library(vkbootstrap STATIC)

target_sources(vkbootstrap PRIVATE
    vk-bootstrap/src/VkBootstrap.cpp
    vk-bootstrap/src/VkBootstrap.h
)

target_include_directories(vkbootstrap PUBLIC vk-bootstrap/src)
target_link_libraries(vkbootstrap PUBLIC Vulkan::Vulkan $<$<BOOL:UNIX>:${CMAKE_DL_LIBS}>)
set_property(TARGET vkbootstrap PROPERTY CXX_STANDARD 20)

#SDL
add_subdirectory(SDL EXCLUDE_FROM_ALL)
