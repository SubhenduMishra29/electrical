# Add the subdirectories where each module has its own CMake configuration
add_subdirectory(cpu)
add_subdirectory(memory)
add_subdirectory(peripherals)
add_subdirectory(mcu)
add_subdirectory(twi)
add_subdirectory(watchdogtimer)
add_subdirectory(communication)
add_subdirectory(gui)  # Make sure the GUI module builds properly

# Create the AVR_Simulation executable
add_executable(AVR_Simulation main.cpp)

# GTK3 package via pkg-config (make sure pkg-config is available)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

# Include GTK directories and compile options
target_include_directories(AVR_Simulation PRIVATE ${GTK_INCLUDE_DIRS})
target_compile_options(AVR_Simulation PRIVATE ${GTK_CFLAGS})

# Add explicit library search path for GUI
target_link_directories(AVR_Simulation PRIVATE ${CMAKE_BINARY_DIR}/src/gui)

# Link libraries correctly
target_link_libraries(AVR_Simulation 
    CPU
    Memory
    Peripherals
    MCU
    TWI
    WatchdogTimer
    SerialCommunication
    GUI  # Ensure this matches the actual GUI library name
    ${GTK_LIBRARIES}
)

# Ensure GTK linker flags are properly added
target_link_options(AVR_Simulation PRIVATE ${GTK_LDFLAGS})

# Debugging messages
message(STATUS "GTK Include Dirs: ${GTK_INCLUDE_DIRS}")
message(STATUS "GTK Libraries: ${GTK_LIBRARIES}")
