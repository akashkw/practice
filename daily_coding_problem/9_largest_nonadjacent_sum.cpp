#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>

#include "gtest/gtest.h"

using namespace std;

/*
 * Problem Statement
 *
 * This problem was asked by Airbnb.
 * 
 * Given a list of integers, write a function that returns the largest sum of non-adjacent numbers.
 * 
 * Numbers can be 0 or negative.
 * 
 * For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.
 * 
 * Follow-up: Can you do this in O(N) time and constant space? 
 */


#include "cpp/helpers.h"
int lns_helper(const vector<int> &vec, const int &i) {
    if(i==0)
        return vec[i];
    if(i == 1)
        return max(vec[0], vec[1]);
    return max(lns_helper(vec, i-2) + vec[i], lns_helper(vec, i-1));
}
// Solution Function Recursive
int largest_nonadjacent_sum_recursive(const vector<int> &vec) {
    return lns_helper(vec, vec.size()-1);
}

// Solution Function DP
int largest_nonadjacent_sum_dp(const vector<int> &vec) {
    vector<int> largest_sum_at_index(vec.size());
    if(vec.size() == 1)
        return vec[0];    
    if(vec.size() == 2)
        return max(vec[0], vec[1]);    
    for(size_t i = 0; i < vec.size(); ++i) {
        if(i == 0)
            largest_sum_at_index[i] = vec[0];
        else if(i == 1)
            largest_sum_at_index[i] = max(vec[0], vec[1]);
        else {
            int choice_one = largest_sum_at_index[i-2] + vec[i];
            int choice_two = largest_sum_at_index[i-1];
            largest_sum_at_index[i] = max(choice_one, choice_two);
        }
    }
    return largest_sum_at_index.back();
}

// Solution Function DP
int largest_nonadjacent_sum_2v(const vector<int> &vec) {
    int two_before = vec[0];
    if(vec.size() == 1)
        return two_before; 
    int one_before = max(vec[0], vec[1]);
    if(vec.size() == 2)
        return one_before;    
    for(size_t i = 2; i < vec.size(); i++) {
        int val_including_this = two_before + vec[i];
        two_before = one_before;
        one_before = max(one_before, val_including_this);
    }
    return one_before;
}

TEST(SolutionFixture, test_1) {
    vector<int> vec = {2,4,6,2,5};
    ASSERT_EQ(largest_nonadjacent_sum_recursive(vec), 13);
}

TEST(SolutionFixture, test_2) {
    vector<int> vec = {5,1,1,5};
    ASSERT_EQ(largest_nonadjacent_sum_recursive(vec), 10);
}

TEST(SolutionFixture, test_3) {
    vector<int> vec = {2,4,6,2,5};
    ASSERT_EQ(largest_nonadjacent_sum_dp(vec), 13);
}

TEST(SolutionFixture, test_4) {
    vector<int> vec = {5,1,1,5};
    ASSERT_EQ(largest_nonadjacent_sum_dp(vec), 10);
}

TEST(SolutionFixture, test_5) {
    vector<int> vec = {2,4,6,2,5};
    ASSERT_EQ(largest_nonadjacent_sum_2v(vec), 13);
}

TEST(SolutionFixture, test_6) {
    vector<int> vec = {5,1,1,5};
    ASSERT_EQ(largest_nonadjacent_sum_2v(vec), 10);
}