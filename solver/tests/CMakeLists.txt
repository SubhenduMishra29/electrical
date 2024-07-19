# tests/CMakeLists.txt

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Test source files
file(GLOB TEST_SOURCES "*.cpp")

# Create executable for tests
add_executable(integration_tests ${TEST_SOURCES})

# Link the main project library if needed
target_link_libraries(integration_tests Power_Lib)

# Add tests
add_test(NAME integration_tests COMMAND integration_tests)
