#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

/*
 * Problem Statement
 * 
 * This problem was asked by Facebook.
 * 
 * Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
 * 
 * For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
 * 
 * You can assume that the messages are decodable. For example, '001' is not allowed.
 */

// Solution Function
int count_decodings(const string &str) {
    return 0;
}

TEST(SolutionFixture, test_1) {
    string encoded = "1";
    ASSERT_EQ(count_decodings(encoded), 1);
}

TEST(SolutionFixture, test_2) {
    string encoded = "111";
    ASSERT_EQ(count_decodings(encoded), 3);
}

TEST(SolutionFixture, test_3) {
    string encoded = "121";
    ASSERT_EQ(count_decodings(encoded), 3);
}

TEST(SolutionFixture, test_4) {
    string encoded = "1234";
    ASSERT_EQ(count_decodings(encoded), 3);
}

TEST(SolutionFixture, test_5) {
    string encoded = "1234421211236";
    ASSERT_EQ(count_decodings(encoded), 63);
}
