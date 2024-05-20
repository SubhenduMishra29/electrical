cmake_minimum_required(VERSION 3.10)
project(ContactorsSimulation)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header directory
include_directories(header)

# Create bin directory
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

# Add executable
add_executable(ContactorsSimulation 
    src/main.cpp 
    src/Contactor.cpp 
    src/ContactFunctions.cpp
)

# Set output directory to bin
set_target_properties(ContactorsSimulation PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
)
