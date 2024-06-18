// unit_tests.cpp

#include <gtest/gtest.h>
#include "generator.h"

// Test fixture for Generator class
class GeneratorTest : public ::testing::Test {
protected:
    Generator generator;

    // SetUp() is called immediately before each test
    void SetUp() override {
        // Initialize generator with capacity 100 MW and type "Thermal"
        generator = Generator(100, "Thermal");
    }

    // TearDown() is called immediately after each test
    void TearDown() override {
        // Clean up any resources if needed
    }
};

// Test case to verify initial conditions of Generator
TEST_F(GeneratorTest, InitialConditions) {
    EXPECT_EQ(generator.getCurrentOutput(), 0.0);
}

// Test case to verify setting output within capacity
TEST_F(GeneratorTest, SetOutputWithinCapacity) {
    generator.setOutput(50);
    EXPECT_EQ(generator.getCurrentOutput(), 50);
}

// Test case to verify setting output exceeding capacity
TEST_F(GeneratorTest, SetOutputExceedingCapacity) {
    // Output should not exceed generator capacity (100 MW)
    generator.setOutput(150);
    EXPECT_NE(generator.getCurrentOutput(), 150);  // Check that output remains within capacity
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
