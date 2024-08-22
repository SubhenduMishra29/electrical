#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>

// Declare the lexer and parser functions
extern "C" {
    int yyparse();
    extern std::stringstream* yyin_stream; // Use a stream pointer
}

void run_test(const std::string& input_file, const std::string& expected_file) {
    std::ifstream input_stream(input_file);
    std::ifstream expected_stream(expected_file);

    if (!input_stream || !expected_stream) {
        std::cerr << "Error opening file(s)." << std::endl;
        exit(1);
    }

    std::stringstream input_buffer;
    input_buffer << input_stream.rdbuf();
    std::string input = input_buffer.str();

    std::stringstream expected_buffer;
    expected_buffer << expected_stream.rdbuf();
    std::string expected = expected_buffer.str();

    // Use a different name for the stringstream to avoid conflicts
    std::stringstream test_input_stream;
    test_input_stream.str(input);

    // Redirect input to the lexer/parser
    yyin_stream = &test_input_stream;

    // Run the parser
    if (yyparse() != 0) {
        std::cerr << "Parser failed." << std::endl;
        exit(1);
    }

    // Capture output
    // Here, you would normally redirect the output of the parser to a string and compare it with `expected`.
    // This depends on how your lexer/parser prints the results.

    // For now, this is a placeholder for capturing output
    std::string actual = "output from parser"; // Replace with actual output capturing logic

    // Compare expected and actual output
    if (expected != actual) {
        std::cerr << "Test failed for " << input_file << std::endl;
        std::cerr << "Expected: " << expected << std::endl;
        std::cerr << "Actual: " << actual << std::endl;
        exit(1);
    } else {
        std::cout << "Test passed for " << input_file << std::endl;
    }
}

int main() {
    // Define test cases
    run_test("tests/test_input_1.txt", "tests/expected_output_1.txt");
    run_test("tests/test_input_2.txt", "tests/expected_output_2.txt");
    
    return 0;
}
