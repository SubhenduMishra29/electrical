#include <gtest/gtest.h> // Include Google Test headers
#include "generator.h"   // Include the header file for the Generator class

class GeneratorTest : public ::testing::Test {
protected:
    // This function runs before each test
    void SetUp() override {
        // Initialize your test objects here
    }

    // This function runs after each test
    void TearDown() override {
        // Clean up your test objects here
    }

    // You can define member variables here that can be used in your tests
    Generator generator;
};

// Example test case
TEST_F(GeneratorTest, ExampleTest) {
    // Test some functionality of the Generator class
    // For example, checking the initial state of the generator
    ASSERT_EQ(generator.getSomeState(), expectedState);
}
