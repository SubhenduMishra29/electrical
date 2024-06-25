cmake_minimum_required(VERSION 3.0)
project(main_app)

# Find GTKmm
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

# Main application executable
add_executable(main_app main.cpp)

# Link against GTKmm libraries
target_link_libraries(main_app PRIVATE ${GTKMM_LIBRARIES})

# Add subdirectories for other components if necessary
add_subdirectory(electrical)

# Link against the GUI module
target_link_libraries(main_app PRIVATE gui_module)
