#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

#include "cpp/helpers.h"

using namespace std;

/*
 * Problem Statement
 *
 * This problem was asked by Uber.
 *
 * Given an array of integers, return a new array such that each element at
 * index i of the new array is the product of all the numbers in the 
 * original array except the one at i.
 *
 * For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
 * If our input was [3, 2, 1], the expected output would be [2, 3, 6].
 *
 * Follow-up: what if you can't use division?
 */

// Solution Function
vector<int> product_array(const vector<int> &vec) {
    int64_t product = 1;
    // find the product of whole array
    for(const int &i : vec)
        product *= i;
    vector<int> solution(vec.size());
    // fill each value with product / val
    for(size_t i = 0; i < vec.size(); ++i)
        solution[i] = product / vec[i];
    return solution;
}

// vec   array [  1,  2,  3,  4,  5]
// right array [120, 60, 20,  5,  1]
// left array  [  1,  1,  2,  6, 24]
vector<int> bonus_product_array(const vector<int> &vec) {
    // special case for if array has size 2
    if(vec.size() == 2) {
        return {vec[1], vec[0]};
    }
    // we will create two arrays to cache the left and right
    // multiplication values, excluding the current value
    vector<int> left_array(vec.size(), 1);
    vector<int> right_array(vec.size(), 1);

    // fill values of right array starting from right side
    for(int i = right_array.size()-2; i >= 0; --i) {
        right_array[i] = right_array[i+1] * vec[i+1];
    }
    // fill values of left array starting from left side
    for(size_t i = 1; i < left_array.size(); ++i) {
        left_array[i] = left_array[i-1] * vec[i-1];
    }
    
    // solution is just the left * right at each position 
    vector<int> solution(vec.size(), 1);
    for(size_t i = 0; i < solution.size(); ++i) {
        solution[i] = left_array[i] * right_array[i];
    }
    return solution;
}

TEST(SolutionFixture, test_1) {
    vector<int> vec = product_array({1,2,3,4,5});
    vector<int> solution = {120,60,40,30,24};
    ASSERT_EQ(vec_string<int>(vec), vec_string<int>(solution));
}
TEST(SolutionFixture, test_2) {
    vector<int> vec = product_array({3,2,1});
    vector<int> solution = {2,3,6};
    ASSERT_EQ(vec_string<int>(vec), vec_string<int>(solution));
}
TEST(SolutionFixture, test_3) {
    vector<int> vec = product_array({-3,2,1});
    vector<int> solution = {2,-3,-6};
    ASSERT_EQ(vec_string<int>(vec), vec_string<int>(solution));
}
TEST(SolutionFixture, test_4) {
    vector<int> vec = product_array({-3,1,-8,3});
    vector<int> solution = {-24,72,-9,24};
    ASSERT_EQ(vec_string<int>(vec), vec_string<int>(solution));
}
TEST(SolutionFixture, test_5) {
    vector<int> vec = product_array({-3,1});
    vector<int> solution = {1,-3};
    ASSERT_EQ(vec_string<int>(vec), vec_string<int>(solution));
}
TEST(BonusSolutionFixture, test_1) {
    vector<int> vec = bonus_product_array({1,2,3,4,5});
    vector<int> solution = {120,60,40,30,24};
    ASSERT_EQ(vec_string<int>(vec), vec_string<int>(solution));
}
TEST(BonusSolutionFixture, test_2) {
    vector<int> vec = bonus_product_array({3,2,1});
    vector<int> solution = {2,3,6};
    ASSERT_EQ(vec_string<int>(vec), vec_string<int>(solution));
}
TEST(BonusSolutionFixture, test_3) {
    vector<int> vec = bonus_product_array({-3,2,1});
    vector<int> solution = {2,-3,-6};
    ASSERT_EQ(vec_string<int>(vec), vec_string<int>(solution));
}
TEST(BonusSolutionFixture, test_4) {
    vector<int> vec = bonus_product_array({-3,1,-8,3});
    vector<int> solution = {-24,72,-9,24};
    ASSERT_EQ(vec_string<int>(vec), vec_string<int>(solution));
}
TEST(BonusSolutionFixture, test_5) {
    vector<int> vec = bonus_product_array({-3,1});
    vector<int> solution = {1,-3};
    ASSERT_EQ(vec_string<int>(vec), vec_string<int>(solution));
}
