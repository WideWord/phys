cmake_minimum_required(VERSION 2.8)

file(GLOB SOURCE_PHYS
    "*.cc"
)	


add_executable(phys ${SOURCE_PHYS})

if(UNIX)
	add_definitions( -DPHYS_LINUX )

	if(CMAKE_COMPILER_IS_GNUCC)
		set_target_properties(phys PROPERTIES COMPILE_FLAGS "-std=c++0x" LINK_FLAGS "-Wl,-rpath,.")
	else()
		message(FATAL_ERROR "Unsupported compiler")
	endif()
elseif(MSVC)
	message(WARNING "Check you msvc")
endif()


find_package(glfw REQUIRED)
include_directories(${glfw_INCLUDE_DIRS})
target_link_libraries(phys ${glfw_LIBRARIES})

find_package(glew REQUIRED)
include_directories(${glew_INCLUDE_DIRS})
target_link_libraries(phys ${glew_LIBRARIES})

if(UNIX)
	target_link_libraries(phys rt X11 GL pthread m Xrandr)
endif()
