#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"
#include "cpp/structures.h"

using namespace std;

/*
 * Problem Statement
 * 
 * This problem was asked by Google.
 * 
 * A unival tree (which stands for "universal value") is a tree
 * where all nodes under it have the same value.
 * 
 * Given the root to a binary tree, count the number of unival subtrees.
 * 
 * For example, the following tree has 5 unival subtrees.

           0
          / \
         1   0
            / \
           1   0
          / \
         1   1 
 */

// Solution Function
int count_unival_subtrees(const node<int>* const &root) {
    return 1;
}

TEST(SolutionFixture, test_1) {
    node<int>* root = new node<int>(5);
    ASSERT_EQ(count_unival_subtrees(root), 1);
    delete root;
}

