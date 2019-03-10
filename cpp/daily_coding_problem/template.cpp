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
 */

// Solution Function
bool solution(int num) {
    return num;
}

TEST(SolutionFixture, test_1) {
    ASSERT_TRUE(solution(1));
}

