cmake_minimum_required(VERSION 3.10)
project(PowerSystemSimulation)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_BINARY_DIR})  # Include the build directory for generated files

# Add subdirectory for libraries
add_subdirectory(lib)
message(STATUS "Include directories: ${CMAKE_SOURCE_DIR}/include")

# Specify the path to Flex and Bison if needed
set(FLEX_EXECUTABLE "C:/GnuWin32/flex.exe")
set(BISON_EXECUTABLE "C:/GnuWin32/bison.exe")
set(FL_LIBRARY "C:/GnuWin32/lib/libfl.a")

# Find Flex and Bison
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# Define directories for generated files
set(BISON_OUTPUT_DIR ${CMAKE_BINARY_DIR})
set(FLEX_OUTPUT_DIR ${CMAKE_BINARY_DIR})

# Bison target
BISON_TARGET(
    Parser
    ${CMAKE_SOURCE_DIR}/lib/parser.y
    ${BISON_OUTPUT_DIR}/parser.tab.cpp
    DEFINES_FILE ${BISON_OUTPUT_DIR}/parser.tab.hpp
    COMPILE_FLAGS ""  # Ensure no extra flags are passed
)

# Flex target
FLEX_TARGET(
    Lexer
    ${CMAKE_SOURCE_DIR}/lib/lexer.l
    ${FLEX_OUTPUT_DIR}/lex.yy.cpp
    COMPILE_FLAGS ""  # Ensure no extra flags are passed
)

# Ensure Flex and Bison are executed before compiling
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

# Source files for the main executable
file(GLOB SOURCES "src/*.cpp")

# Create main executable
add_executable(${PROJECT_NAME} ${SOURCES}
    ${BISON_OUTPUT_DIR}/parser.tab.cpp
    ${FLEX_OUTPUT_DIR}/lex.yy.cpp
)

# Link libraries to the executable
target_link_libraries(${PROJECT_NAME} Power_Lib ${FL_LIBRARY})

# Optionally, add testing
# enable_testing()
# add_subdirectory(tests)
