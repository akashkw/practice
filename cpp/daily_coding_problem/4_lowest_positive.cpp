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
 * This problem was asked by Stripe.
 * Given an array of integers, find the first missing positive integer in
 * linear time and constant space. In other words, find the lowest 
 * positive integer that does not exist in the array. The array can 
 * contain duplicates and negative numbers as well.
 *
 * For example, the input [3, 4, -1, 1] should give 2. 
 * The input [1, 2, 0] should give 3.
 * You can modify the input array in-place.
 */

// Solution Function
// [1,5,2,4]
int lowest_positive(const vector<int> &vec) {
    return 1;
}

TEST(SolutionFixture, test_1) {
    vector<int> vec = {3,4,-1,1};
    ASSERT_EQ(lowest_positive(vec), 2);
}
TEST(SolutionFixture, test_2) {
    vector<int> vec = {1,2,0};
    ASSERT_EQ(lowest_positive(vec), 3);
}
