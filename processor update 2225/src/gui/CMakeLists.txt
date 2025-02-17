# Declare the GUI project and specify the C++ language
project(GUI CXX)

# Ensure pkg-config is available to find GTK3
find_package(PkgConfig REQUIRED)

# Use pkg-config to get GTK3 details
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Include GTK3 headers
include_directories(${GTK3_INCLUDE_DIRS})

# Link GTK3 libraries
link_directories(${GTK3_LIBRARY_DIRS})

# Add any necessary compiler flags (from pkg-config)
add_definitions(${GTK3_CFLAGS_OTHER})

# Add the GUI source files
add_library(GUI STATIC src/gui.cpp src/main_window.cpp)

# Ensure proper linking of GTK3 libraries
target_link_libraries(GUI ${GTK3_LIBRARIES})

# Optional: Debugging GTK3 information
message(STATUS "GTK3 Include Dirs: ${GTK3_INCLUDE_DIRS}")
message(STATUS "GTK3 Libraries: ${GTK3_LIBRARIES}")
