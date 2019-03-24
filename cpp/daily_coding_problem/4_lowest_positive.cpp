#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"
#include "test/helpers.h"

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
    vector<int>::reverse_iterator swap_spot(vec.rbegin());
    for(vector<int>::reverse_iterator curr(vec.rbegin()); curr != vec.rend(); ++curr) {
        if(*curr < 1) {
            int tmp = *curr;
            *curr = *swap_spot;
            *swap_spot = tmp;
            ++swap_spot;
        }
    } 
    // point to the first invalid value (one after last good value, like end(vec))
    vector<int>::iterator new_end(swap_spot.base());
    
    cout << vec_string(vec) << endl;

    return 0;
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
