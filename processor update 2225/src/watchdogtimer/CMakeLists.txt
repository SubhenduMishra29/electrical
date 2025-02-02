add_library(WatchdogTimer STATIC watchdogtimer.cpp)
target_include_directories(WatchdogTimer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
