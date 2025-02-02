add_library(MCU MCU.cpp)
target_include_directories(MCU PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MCU PUBLIC CPU Memory Peripherals)

# Link the SerialCommunication library
target_link_libraries(MCU PRIVATE SerialCommunication)
