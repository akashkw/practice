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

// Solution Function
int largest_nonadjacent_sum(const vector<int> &vec) {
    if(vec.size() < 3) {
        if(vec.size() == 1)
            return vec[0];
        return max(vec[0], vec[1]);
    }
    vector<int> largest_sum_at_index(vec.size());
    largest_sum_at_index[0] = vec[0];
    largest_sum_at_index[1] = max(vec[0], vec[1]);
    for(size_t i = 2; i < vec.size(); ++i) {
        int choice_one = largest_sum_at_index[i-2] + vec[i];
        int choice_two = largest_sum_at_index[i-1];
        largest_sum_at_index[i] = max(choice_one, choice_two);
    }
    return *(max_element(begin(largest_sum_at_index), end(largest_sum_at_index)));
}

TEST(SolutionFixture, test_1) {
    vector<int> vec = {2,4,6,2,5};
    ASSERT_EQ(largest_nonadjacent_sum(vec), 13);
}

TEST(SolutionFixture, test_2) {
    vector<int> vec = {5,1,1,5};
    ASSERT_EQ(largest_nonadjacent_sum(vec), 10);
}
