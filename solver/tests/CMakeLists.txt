# Add the test executable
add_executable(BFT
    run_tests.cpp
    ${BISON_OUTPUT_DIR}/parser.tab.cpp
    ${FLEX_OUTPUT_DIR}/lex.yy.cpp
)

# Link the test executable with the library
target_link_libraries(BFT PowerSystemLib ${FL_LIBRARY})

# Define the test case
add_test(NAME BFT COMMAND BFT)
