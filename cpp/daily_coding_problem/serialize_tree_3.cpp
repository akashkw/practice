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
 * This problem was asked by Google.
 * Given the root to a binary tree, implement serialize(root), which serializes 
 * the tree into a string, and deserialize(s), which deserializes the string 
 * back into the tree.
 * For example, given the following Node class
 
 * class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

 * The following test should pass:
   node = Node('root', Node('left', Node('left.left')), Node('right'))
   assert deserialize(serialize(node)).left.left.val == 'left.left'
 */

// Solution Function
bool solution(int num) {
    return num;
}

TEST(SolutionFixture, test_1) {
    ASSERT_TRUE(solution(1));
}

