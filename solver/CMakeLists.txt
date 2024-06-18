cmake_minimum_required(VERSION 3.10)
project(PowerSystemSimulation)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Optional: Add libraries (if you create your own library)
# add_subdirectory(path_to_your_library)

# Optional: Link your library to the executable
# target_link_libraries(${PROJECT_NAME} YourLibraryName)

# Optional: Add testing
enable_testing()
add_subdirectory(tests)
