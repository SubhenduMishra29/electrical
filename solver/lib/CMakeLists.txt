# lib/CMakeLists.txt

# Source files for the library
file(GLOB LIB_SOURCES "${CMAKE_SOURCE_DIR}/src/lib/*.cpp")

# Create a static library
add_library(Power_Lib STATIC ${LIB_SOURCES})

# Optionally, you can create a shared library instead
# add_library(Power_Lib SHARED ${LIB_SOURCES})

# Include directories for the library
target_include_directories(Power_Lib PUBLIC ${CMAKE_SOURCE_DIR}/include)