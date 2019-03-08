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
    for(const int &i : vec)
        product *= i;
    vector<int> solution(vec.size());
    for(size_t i = 0; i < vec.size(); ++i)
        solution[i] = product / vec[i];
    return solution;
}

vector<int> bonus_product_array(const vector<int> &vec) {
    if(vec.size() == 2) {
        return {vec[1], vec[0]};
    }
    vector<int> left_array(vec.size(), 1);
    vector<int> right_array(vec.size(), 1);
    right_array[right_array.size() - 2] = vec[right_array.size()-1];
    left_array[1] = vec[0];
    for(int i = (int)right_array.size()-3; i >= 0; --i) {
        right_array[i] = right_array[i+1] * right_array[i+2];
    }
    for(size_t i = 2; i <= left_array.size()-1; ++i) {
        left_array[i] = left_array[i-1] * right_array[i-2];
    }
    vector<int> solution(vec.size());
    solution[0] = right_array[1];
    solution[solution.size()-1] = left_array[solution.size()-2];
    for(size_t i = 1; i < vec.size() - 1; ++i) {
        solution[i] = left_array[i-1] * right_array[i+1];
    }
    return solution;
}

TEST(SolutionFixture, test_1) {
    vector<int> vec = product_array({1,2,3,4,5});
    vector<int> solution = {120,60,40,30,24};
    ASSERT_TRUE(equal(begin(vec), end(vec), begin(solution)));
}
TEST(SolutionFixture, test_2) {
    vector<int> vec = product_array({3,2,1});
    vector<int> solution = {2,3,6};
    ASSERT_TRUE(equal(begin(vec), end(vec), begin(solution)));
}
TEST(SolutionFixture, test_3) {
    vector<int> vec = product_array({-3,2,1});
    vector<int> solution = {2,-3,-6};
    ASSERT_TRUE(equal(begin(vec), end(vec), begin(solution)));
}
TEST(SolutionFixture, test_4) {
    vector<int> vec = product_array({-3,1,-8,3});
    vector<int> solution = {-24,72,-9,24};
    ASSERT_TRUE(equal(begin(vec), end(vec), begin(solution)));
}
TEST(SolutionFixture, test_5) {
    vector<int> vec = product_array({-3,1});
    vector<int> solution = {1,-3};
    ASSERT_TRUE(equal(begin(vec), end(vec), begin(solution)));
}
TEST(BonusSolutionFixture, test_1) {
    vector<int> vec = bonus_product_array({1,2,3,4,5});
    vector<int> solution = {120,60,40,30,24};
    ASSERT_TRUE(equal(begin(vec), end(vec), begin(solution)));
}
TEST(BonusSolutionFixture, test_2) {
    vector<int> vec = bonus_product_array({3,2,1});
    vector<int> solution = {2,3,6};
    ASSERT_TRUE(equal(begin(vec), end(vec), begin(solution)));
}
TEST(BonusSolutionFixture, test_3) {
    vector<int> vec = bonus_product_array({-3,2,1});
    vector<int> solution = {2,-3,-6};
    ASSERT_TRUE(equal(begin(vec), end(vec), begin(solution)));
}
TEST(BonusSolutionFixture, test_4) {
    vector<int> vec = bonus_product_array({-3,1,-8,3});
    vector<int> solution = {-24,72,-9,24};
    ASSERT_TRUE(equal(begin(vec), end(vec), begin(solution)));
}
TEST(BonusSolutionFixture, test_5) {
    vector<int> vec = bonus_product_array({-3,1});
    vector<int> solution = {1,-3};
    ASSERT_TRUE(equal(begin(vec), end(vec), begin(solution)));
}
