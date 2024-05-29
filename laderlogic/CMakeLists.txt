cmake_minimum_required(VERSION 3.10)

# Set the project name
project(LadderLogicSimulator)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(LadderLogicSimulator
    main.cpp
    simulator.cpp
    rung.cpp
    pushbutton.cpp
    contact.cpp
    coil.cpp
    bulb.cpp
)

# Include directories
target_include_directories(LadderLogicSimulator PUBLIC
    "${PROJECT_SOURCE_DIR}"
)
