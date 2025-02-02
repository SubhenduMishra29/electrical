cmake_minimum_required(VERSION 3.16)
if(${CMAKE_VERSION} VERSION_LESS "3.16")
  message(FATAL_ERROR "CMake version 3.16 or higher is required. You are running version ${CMAKE_VERSION}")
endif()

project(AVR_Simulation_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Check for required packages
find_package(Threads REQUIRED)
cmake_policy(SET CMP0167 NEW)


# Set up necessary configurations
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Add subdirectories
add_subdirectory(src)

