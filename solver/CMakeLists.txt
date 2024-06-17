cmake_minimum_required(VERSION 3.10)
project(PowerFlowSolver)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(PowerFlowSolver
    src/bus.cpp
    src/line.cpp
    src/powerflow.cpp
    src/jacobian.cpp
    src/main.cpp
)

