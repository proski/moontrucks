# Simulation for a lunar Helium-3 space mining operation.

# Minimum supported cmake version
cmake_minimum_required(VERSION 3.15)

# Project properties
project(
	MoonTrucks
	VERSION 1.0
	LANGUAGES CXX
)

# C++ version
set(CMAKE_CXX_STANDARD 17)

# Library for the core implementation
add_library(MoonTrucks
	event_queue.cpp
)

# The executable file
add_executable(moontrucks moontrucks.cpp)

# Libraries for the executable file
target_link_libraries(moontrucks PRIVATE MoonTrucks)

add_custom_target(
	format
	clang-format -i *.cpp *.h
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

