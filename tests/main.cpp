#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>
#include "parser.tab.hpp"  // Ensure the correct path to the generated header file is included

// Declare the global variable for the lexer input stream
std::stringstream* yyin_stream;

// Function to capture parser output
std::string capture_parser_output() {
    std::string output;
    std::stringstream buffer;

    // Redirect std::cout to capture the output
    std::streambuf* original = std::cout.rdbuf(buffer.rdbuf());

    std::cout << "Starting parser..." << std::endl;

    // Call the parser
    int result = yyparse();
    
    if (result != 0) {
        std::cerr << "Parser failed with result: " << result << std::endl;
    }

    std::cout << "Parser finished." << std::endl;

    // Restore original std::cout buffer
    std::cout.rdbuf(original);

    // Get the output from the buffer
    output = buffer.str();
    return output;
}

// Function to run a single test
void run_test(const std::string& input_file, const std::string& expected_file) {
    std::ifstream input_stream(input_file);
    std::ifstream expected_stream(expected_file);

    // Check if files are opened successfully
    if (!input_stream.is_open()) {
        std::cerr << "Error opening input file: " << input_file << std::endl;
        return;
    }
    if (!expected_stream.is_open()) {
        std::cerr << "Error opening expected file: " << expected_file << std::endl;
        return;
    }

    // Read content of input file
    std::stringstream input_buffer;
    input_buffer << input_stream.rdbuf();
    std::string input = input_buffer.str();

    // Read content of expected file
    std::stringstream expected_buffer;
    expected_buffer << expected_stream.rdbuf();
    std::string expected = expected_buffer.str();

    // Create a stream for lexer input
    std::stringstream test_input_stream;
    test_input_stream.str(input);

    yyin_stream = &test_input_stream;

    // Capture the output from the parser
    std::string actual = capture_parser_output();

    // Print debugging information
    std::cout << "Expected Output:\n" << expected << std::endl;
    std::cout << "Actual Output:\n" << actual << std::endl;

    // Compare actual and expected outputs
    if (expected != actual) {
        std::cerr << "Test failed for " << input_file << std::endl;
        std::cerr << "Expected: " << expected << std::endl;
        std::cerr << "Actual: " << actual << std::endl;
    } else {
        std::cout << "Test passed for " << input_file << std::endl;
    }
}

int main() {
    std::cout << "The main method Started" << std::endl;
    run_test("tests/test_input_1.txt", "tests/expected_output_1.txt");
    run_test("tests/test_input_2.txt", "tests/expected_output_2.txt");
    std::cout << "The main method ends" << std::endl;
    return 0;
}
