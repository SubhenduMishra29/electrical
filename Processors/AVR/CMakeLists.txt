# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(AVRProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)  # Switch to C++17 or a newer version

# Add the core subdirectory
add_subdirectory(core)

# Optionally, specify other directories if needed
# Example: add_subdirectory(some_other_component)
# Add the test directory
add_subdirectory(test)
