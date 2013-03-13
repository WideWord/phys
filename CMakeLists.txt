cmake_minimum_required(VERSION 2.7)
project(phys)

file(GLOB phys_src
    "src/*.h"
    "src/*.cc"
    "src/*/*.cc"
    "src/*/*.h"
    "src/*/*.c"
    "src/*.c"
)

add_definitions(-DPHYS_LINUX)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
add_executable(phys ${phys_src})
TARGET_LINK_LIBRARIES(phys glfw GLEW Box2D X11 GL Xxf86vm pthread rt)
