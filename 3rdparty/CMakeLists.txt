#vk-bootstrap
add_library(vkbootstrap STATIC)

target_sources(vkbootstrap PRIVATE
vk-bootstrap/src/VkBootstrap.cpp
vk-bootstrap/src/VkBootstrap.h
)

target_include_directories(vkbootstrap PUBLIC vk-bootstrap/src)
target_link_libraries()

#SDL
add_subdirectory(SDL EXCLUDE_FROM_ALL)