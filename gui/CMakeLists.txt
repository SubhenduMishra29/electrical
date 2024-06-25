# Define the library
add_library(gui_module STATIC gui_component.cpp)

# Find GTKmm
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

# Link against GTKmm
target_link_libraries(gui_module PRIVATE ${GTKMM_LIBRARIES})
target_include_directories(gui_module PUBLIC ${GTKMM_INCLUDE_DIRS})

# Optionally, link against other dependencies specific to your GUI module
# target_link_libraries(gui_module PRIVATE other_library)
# target_include_directories(gui_module PUBLIC path_to_other_library_include_directory)
