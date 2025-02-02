add_library(TWI STATIC twi.cpp)
target_include_directories(TWI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
