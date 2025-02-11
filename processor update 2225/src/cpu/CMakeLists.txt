 add_library(CPU CPU.cpp InstructionExecution.cpp)
target_include_directories(CPU PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
