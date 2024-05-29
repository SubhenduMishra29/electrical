cmake_minimum_required(VERSION 3.10)

# Set the project name
project(LadderLogicLibrary VERSION 1.0)

# Include header files
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Generate the static library
add_library(ladderlogic STATIC ${SOURCES})

# Specify the installation directory for header files
install(DIRECTORY include/ DESTINATION include)

# Specify the installation directory for the library
install(TARGETS ladderlogic
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

# Build main program
add_executable(main test/main.cpp)
target_link_libraries(main PRIVATE ladderlogic)

# Set the output directory for the main program
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/test"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/test"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/test"
)
