#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "gtest/gtest.h"

using namespace std;

/*
 * Problem Statement
 * This problem was asked by Amazon.
 * 
 * Given an integer k and a string s,
 * Find the length of the longest substring that contains at most k distinct characters.
 * 
 * For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
 */

// Solution Function
string longest_substr_k_dist_chars(const string &str, const size_t &k) {
    size_t beg_i = 0;
    size_t end_i = 0;
    string longest = "";
    unordered_map<char, int> freq_counter;
    ++freq_counter[str[end_i]];
    while(end_i != str.size()) {
        while (freq_counter.size() <= k && end_i != str.size()) {
            ++end_i;
            ++freq_counter[str[end_i]];
        }
        if(end_i-beg_i > longest.size()){
            longest = str.substr(beg_i, end_i - beg_i);
        }
        while(freq_counter.size() > k && beg_i != str.size()) {
            if(!(--freq_counter[str[beg_i]]))
                freq_counter.erase(str[beg_i]);
            ++beg_i;
        }
    }
    return longest;
}

TEST(SolutionFixture, test_1) {
    ASSERT_EQ(longest_substr_k_dist_chars("abcba", 2), "bcb");
}

TEST(SolutionFixture, test_2) {
    ASSERT_EQ(longest_substr_k_dist_chars("akash", 2), "aka");
}

TEST(SolutionFixture, test_3) {
    ASSERT_EQ(longest_substr_k_dist_chars("hello my name is akash", 3), "hell");
}

TEST(SolutionFixture, test_4) {
    ASSERT_EQ(longest_substr_k_dist_chars("hellooo my name is akash", 3), "ellooo");
}