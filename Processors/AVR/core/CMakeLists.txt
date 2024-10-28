# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Automatically set the project name based on the folder name
get_filename_component(LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Add the parser subdirectory explicitly (if at16/parser is static)
add_subdirectory(at16/parser)

# Collect all core source files (*.cpp) inside this directory
file(GLOB_RECURSE CORE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

# Automatically find all subdirectories (that contain CMakeLists.txt)
file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)

# Loop through all found subdirectories and add them as subdirectories
foreach(subdir ${SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir})
        # Check if the subdirectory contains a CMakeLists.txt (to avoid errors)
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt)
            message(STATUS "Adding subdirectory: ${subdir}")
            add_subdirectory(${subdir})
        endif()
    endif()
endforeach()

# Create a core object library using the folder name
add_library(${LIB_NAME} OBJECT ${CORE_SOURCES})

# Set output directories for object files
set_target_properties(${LIB_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${LIB_NAME}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${LIB_NAME}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${LIB_NAME}"
)

# Link CoreObject (core) with the parser library generated in the parser subdirectory
target_link_libraries(${LIB_NAME} PUBLIC ParserLib)

# Include directories (core headers and parser headers)
target_include_directories(${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}                # Core headers
    ${CMAKE_CURRENT_SOURCE_DIR}/at16/parser    # Parser headers (lexer, parser.tab.h)
    ${CMAKE_BINARY_DIR}/at16/parser            # Binary directory where parser.tab.h is generated
    ${CMAKE_CURRENT_SOURCE_DIR}/avr             # AVR common headers
    ${CMAKE_CURRENT_SOURCE_DIR}/util            #AVR utility files
)
