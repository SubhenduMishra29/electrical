# tests/CMakeLists.txt

# Unit tests
add_executable(unit_tests unit_tests.cpp)
target_link_libraries(unit_tests gtest gtest_main)  # Link with Google Test framework

add_test(NAME UnitTests COMMAND unit_tests)

# Integration tests
add_executable(integration_tests integration_tests.cpp)
target_link_libraries(integration_tests gtest gtest_main)  # Link with Google Test framework

add_test(NAME IntegrationTests COMMAND integration_tests)
