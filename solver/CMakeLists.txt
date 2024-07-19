cmake_minimum_required(VERSION 3.10)
project(PowerSystemSimulation)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectory for libraries
add_subdirectory(lib)
# message to check path 
message(STATUS "Include directories: ${CMAKE_SOURCE_DIR}/include")

# Source files for the main executable
file(GLOB SOURCES "src/*.cpp")

# Create main executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries to the executable
target_link_libraries(${PROJECT_NAME} Power_Lib)

# Add testing
#enable_testing()
#add_subdirectory(tests)
