#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "gtest/gtest.h"
#include "cpp/helpers.h"

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
int lowest_positive(vector<int> vec) {
    // swapping algorithm to filter out invalid values
    // should push all values less than 1 to the back
    vector<int>::reverse_iterator swap_spot(rbegin(vec));
    for(vector<int>::reverse_iterator curr(rbegin(vec)); curr != rend(vec); ++curr) {
        if(*curr < 1) {
            *curr ^= *swap_spot;
            *swap_spot ^= *curr;
            *curr ^= *swap_spot;
            ++swap_spot;
        }
    } 
    // point to the first invalid value (one after last good value, like end(vec))
    vector<int>::iterator new_end(swap_spot.base());

    for(vector<int>::iterator curr(begin(vec)); curr != new_end; ++curr) {
        if((size_t)abs(*curr) <= vec.size()) {
            vec[abs(*curr)-1] *= -1;
        }
    }

    for(int i = 0; i < (new_end - begin(vec)); ++i) {
        if(vec[i] > 0) {
            return i+1;
        }
    }
    return new_end - begin(vec) + 1;    
}

TEST(SolutionFixture, test_1) {
    vector<int> vec = {3,4,-1,1};
    ASSERT_EQ(lowest_positive(vec), 2);
}
TEST(SolutionFixture, test_2) {
    vector<int> vec = {1,2,0};
    ASSERT_EQ(lowest_positive(vec), 3);
}
TEST(SolutionFixture, test_3) {
    vector<int> vec = {10,25,50};
    ASSERT_EQ(lowest_positive(vec), 1);
}
TEST(SolutionFixture, test_4) {
    vector<int> vec = {4,-1,-4,3,1,9,-3,0};
    ASSERT_EQ(lowest_positive(vec), 2);
}
TEST(SolutionFixture, test_5) {
    vector<int> vec = {1,2,3};
    ASSERT_EQ(lowest_positive(vec), 4);
}
TEST(SolutionFixture, test_6) {
    vector<int> vec = {-1,2,3,1};
    ASSERT_EQ(lowest_positive(vec), 4);
}
TEST(SolutionFixture, test_7) {
    vector<int> vec = {6,5,4,3,2,1};
    ASSERT_EQ(lowest_positive(vec), 7);
}
TEST(SolutionFixture, test_8) {
    vector<int> vec = {1,2,3,4,5,6};
    ASSERT_EQ(lowest_positive(vec), 7);
}
TEST(SolutionFixture, test_9) {
    vector<int> vec = {5,1,6,4,2,3};
    ASSERT_EQ(lowest_positive(vec), 7);
}
