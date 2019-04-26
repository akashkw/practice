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
 * This problem was asked by Amazon.
 *
 * There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
 * Given N, write a function that returns the number of unique ways you can climb the staircase.
 * The order of the steps matters.
 * 
 * For example, if N is 4, then there are 5 unique ways:

        1, 1, 1, 1
        2, 1, 1
        1, 2, 1
        1, 1, 2
        2, 2

 * What if, instead of being able to climb 1 or 2 steps at a time,
 * you could climb any number from a set of positive integers X? 
 * For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
 * 
 */

int unique_steps_dp(vector<int> &dp, const size_t &index) {
    if(index == dp.size())
        return 1;
    if(dp[index])
        return dp[index];
    if(index + 1 <= dp.size())
        dp[index] += unique_steps_dp(dp, index + 1);
    if(index + 2 <= dp.size())
        dp[index] += unique_steps_dp(dp, index + 2);
    return dp[index];
}
// Solution Function
int unique_steps(int n) {
    vector<int> dp(n, 0);
    unique_steps_dp(dp, 0);
    return dp[0]; 
}

int unique_steps_custom_dp(vector<int> &dp, const vector<int> &step_sizes, const size_t &index) {
    if(index == dp.size())
        return 1;
    if(dp[index])
        return dp[index];
    for(const int &step : step_sizes) {
        if(index + step <= dp.size())
            dp[index] += unique_steps_custom_dp(dp, step_sizes, index + step);
    }
    return dp[index];
}
// Solution Function
int unique_steps_custom(int n, const vector<int> &step_sizes) {
    vector<int> dp(n, 0);
    unique_steps_custom_dp(dp, step_sizes, 0);
    return dp[0];
}
TEST(SolutionFixture, test_1) {
    ASSERT_EQ(unique_steps(4), 5);
}

TEST(SolutionFixture, test_2) {
    ASSERT_EQ(unique_steps(1), 1);
}

TEST(SolutionFixture, test_3) {
    ASSERT_EQ(unique_steps(2), 2);
}

TEST(SolutionFixture, test_4) {
    ASSERT_EQ(unique_steps(8), 34);
}

TEST(SolutionFixture, test_5) {
    ASSERT_EQ(unique_steps(16), 1597);
}

TEST(SolutionFixture, test_6) {
    ASSERT_EQ(unique_steps_custom(16, {1,2}), 1597);
}

TEST(SolutionFixture, test_7) {
    ASSERT_EQ(unique_steps_custom(4, {1,2,3}), 7);
}

TEST(SolutionFixture, test_8) {
    ASSERT_EQ(unique_steps_custom(2, {1,2,3}), 2);
}

TEST(SolutionFixture, test_9) {
    ASSERT_EQ(unique_steps_custom(5, {1,2,3,4,5}), 16);
}