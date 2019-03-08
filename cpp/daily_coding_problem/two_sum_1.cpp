#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#include "gtest/gtest.h"

using namespace std;

/*
 * Problem Statement
 *
 * This problem was recently asked by Google.
 *
 * Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
 * For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 *
 * Bonus: Can you do this in one pass?
 */

// Solution Function
bool two_sum(const vector<int> &vec, const int &k) {
    if(vec.size() < 2) {
        return false;
    }
    unordered_map<int,int> freq;
    for(const int &i : vec) {
        ++freq[i];
    }
    for(const int &i : vec) {
        if(freq[k-i] == 1 || (freq[k-i] >= 2 && k-i == i))
            return true;
    }
    return false;
}

bool bonus_two_sum(const vector<int> &vec, const int &k) {
    if(vec.size() < 2) {
        return false;
    }
    unordered_set<int> visited;
    for(const int &i : vec) {
        if(visited.find(k - i) != visited.end())
            return true;
        visited.insert(i);
    }
    return false;
}

TEST(SolutionFixture, test_1) {
    vector<int> vec = {10,15,3,7};
    int k = 17;
    ASSERT_TRUE(two_sum(vec, k));
}
TEST(SolutionFixture, test_2) {
    vector<int> vec = {10,15,15,7};
    int k = 30;
    ASSERT_TRUE(two_sum(vec, k));
}
TEST(SolutionFixture, test_3) {
    vector<int> vec = {10};
    int k = 6;
    ASSERT_FALSE(two_sum(vec, k));
}
TEST(SolutionFixture, test_4) {
    vector<int> vec = {10,15,3,7};
    int k = 10;
    ASSERT_TRUE(bonus_two_sum(vec, k));
}
TEST(SolutionFixture, test_5) {
    vector<int> vec = {20,15,3,7};
    int k = 11;
    ASSERT_FALSE(bonus_two_sum(vec, k));
}

TEST(BonusSolutionFixture, test_1) {
    vector<int> vec = {10,15,3,7};
    int k = 17;
    ASSERT_TRUE(bonus_two_sum(vec, k));
}
TEST(BonusSolutionFixture, test_2) {
    vector<int> vec = {10,15,15,7};
    int k = 30;
    ASSERT_TRUE(bonus_two_sum(vec, k));
}
TEST(BonusSolutionFixture, test_3) {
    vector<int> vec = {10};
    int k = 6;
    ASSERT_FALSE(bonus_two_sum(vec, k));
}
TEST(BonusSolutionFixture, test_4) {
    vector<int> vec = {10,15,3,7};
    int k = 10;
    ASSERT_TRUE(bonus_two_sum(vec, k));
}
TEST(BonusSolutionFixture, test_5) {
    vector<int> vec = {20,15,3,7};
    int k = 11;
    ASSERT_FALSE(bonus_two_sum(vec, k));
}
