#include "Soundex.h"
#include <gtest/gtest.h>

// Test fixture for Soundex functions
class SoundexTest : public ::testing::Test {
protected:
    // Setup code here (if any)
    SoundexTest() {
        // Initialize objects or perform setup steps
    }

    // Teardown code here (if any)
    virtual ~SoundexTest() {
        // Clean up
    }

    // Optional: Define additional helper functions or variables specific to tests
};

// Unit tests

// Test case for getSoundexCode function
TEST_F(SoundexTest, GetSoundexCodeTest) {
    EXPECT_EQ(getSoundexCode('A'), '0'); // Test default case
    EXPECT_EQ(getSoundexCode('B'), '1'); // Test specific mappings
    EXPECT_EQ(getSoundexCode('C'), '2');
    EXPECT_EQ(getSoundexCode('Z'), '2'); // Test case insensitivity
}

// Test case for SoundexLengthCheck function
TEST_F(SoundexTest, SoundexLengthCheckTest) {
    EXPECT_TRUE(SoundexLengthCheck("123")); // Test length check true
    EXPECT_FALSE(SoundexLengthCheck("1234")); // Test length check false
}

// Test case for SoundexCodeCheck function
TEST_F(SoundexTest, SoundexCodeCheckTest) {
    EXPECT_TRUE(SoundexCodeCheck('1', '0')); // Test valid code check
    EXPECT_FALSE(SoundexCodeCheck('1', '1')); // Test invalid code check
}

// Test case for IncrementSoundex function
TEST_F(SoundexTest, IncrementSoundexTest) {
    EXPECT_EQ(IncrementSoundex("S", "Smith", getSoundexCode('S')), "S530"); // Test with specific input
    EXPECT_EQ(IncrementSoundex("S", "Johnson", getSoundexCode('S')), "S525"); // Another test case
    EXPECT_EQ(IncrementSoundex("", "", '0'), "0000"); // Test with empty inputs
}

// Test case for generateSoundex function
TEST_F(SoundexTest, GenerateSoundexTest) {
    EXPECT_EQ(generateSoundex("Smith"), "S530"); // Test with specific input
    EXPECT_EQ(generateSoundex("Johnson"), "J525"); // Another test case
    EXPECT_EQ(generateSoundex(""), "0000"); // Test with empty input
}

// Test case for padSoundex function
TEST_F(SoundexTest, PadSoundexTest) {
    EXPECT_EQ(padSoundex("S5"), "S500"); // Test with less than 4 characters
    EXPECT_EQ(padSoundex("J525"), "J525"); // Test with exactly 4 characters
}

// Entry point for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
