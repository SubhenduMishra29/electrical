cmake_minimum_required(VERSION 3.0)
project(PowerFlowSolver)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable target
add_executable(powerflow_solver main.cpp powerflow.cpp)

# Include header files directory
target_include_directories(powerflow_solver PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
