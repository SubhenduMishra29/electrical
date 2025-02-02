add_library(SerialCommunication STATIC SerialCommunication.cpp)
target_include_directories(SerialCommunication PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
