#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

template <typename T> string vec_string(const vector<T> &vec) {
    ostringstream out;
    out << "[";
    for(size_t i = 0; i < vec.size()-1; ++i)
        out << vec[i] << ",";
    out << vec[vec.size()-1] << "]";
    return out.str();
}

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

// vec   array [1,2,3,4,5]
// right array [120,60,20,5,1]
// left array  [1,1,2,6,24]
vector<int> bonus_product_array(const vector<int> &vec) {
    if(vec.size() == 2) {
        return {vec[1], vec[0]};
    }
    vector<int> left_array(vec.size(), 1);
    vector<int> right_array(vec.size(), 1);
    right_array[vec.size()-2] = vec[vec.size() - 1];
    for (int i = (int)vec.size() - 3; i >= 0; --i) {
        right_array[i] = right_array[i+1] * vec[i+1];
    }
    left_array[1] = vec[0];
    for(size_t i = 2; i < vec.size(); ++i) {
        left_array[i] = left_array[i-1] * vec[i-1];
    }
    vector<int> solution(vec.size(), 1);
    for(size_t i = 0; i < vec.size(); ++i) {
        solution[i] = right_array[i] * left_array[i];
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
