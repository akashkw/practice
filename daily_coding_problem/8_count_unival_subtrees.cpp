#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>

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

// Solution Function - Brute Force
bool is_unival_subtree(const node<int>* const &root, const int &val) {
    if(!root)
        return true;
    if(root->data == val)
        return is_unival_subtree(root->left, val) && is_unival_subtree(root->right, val);
    return false;
}

// Solution Function - Brute Force
int count_unival_subtrees(const node<int>* const &root) {
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 1;
    int count = 0;
    count += count_unival_subtrees(root->left);
    count += count_unival_subtrees(root->right);
    if(is_unival_subtree(root->left, root->data) && is_unival_subtree(root->right, root->data))
            count += 1;
    return count;
}

// Solution Funciton - Optimized
// returns a pair, the first is the num unival subtrees at this node
// the second is a bool indicating if this subtree is uinval according to param val
pair<int, bool> get_unival_data(const node<int>* const &root, const int &val) {
    if(!root) 
        return make_pair(0, true);
    bool maintains_unival = root->data == val;
    if(!root->left && !root->right)
        return make_pair(1, maintains_unival);
    if((root->left && root->left->data != val) || (root->right && root->right->data != val))
        maintains_unival = false;
    pair<int, bool> left_data = get_unival_data(root->left, root->data);
    pair<int, bool> right_data = get_unival_data(root->right, root->data);
    int count = left_data.first + right_data.first;
    if(left_data.second && right_data.second)
        count += 1;
    return make_pair(count, maintains_unival);
}

// Solution Funciton - Optimized
int count_unival_subtrees_opt(const node<int>* const &root) {
    return get_unival_data(root, root->data).first;
}

TEST(SolutionFixture, test_1) {
    node<int>* root = new node<int>(5);
    ASSERT_EQ(count_unival_subtrees(root), 1);
    delete root;
}
TEST(SolutionFixture, test_2) {
    node<int>* root = new node<int>(5);
    root->left = new node<int>(5);
    root->right = new node<int>(5);
    ASSERT_EQ(count_unival_subtrees(root), 3);
    delete root;
}

TEST(SolutionFixture, test_3) {
    node<int>* root = new node<int>(0);
    root->left = new node<int>(1);
    root->right = new node<int>(0);
    root->right->left = new node<int>(1);
    root->right->right = new node<int>(0);
    root->right->left->left = new node<int>(1); root->right->left->right = new node<int>(1);
    ASSERT_EQ(count_unival_subtrees(root), 5);
    delete root;
}

TEST(SolutionFixture, test_4) {
    node<int>* root = new node<int>(5);
    root->left = new node<int>(5);
    root->right = new node<int>(5);
    root->left->left = new node<int>(5);
    root->left->right = new node<int>(5);
    root->right->right = new node<int>(5);
    ASSERT_EQ(count_unival_subtrees(root), 6);
    delete root;
}

TEST(SolutionFixture, test_5) {
    node<int>* root = new node<int>(5);
    root->left = new node<int>(1);
    root->right = new node<int>(5);
    root->left->left = new node<int>(5);
    root->left->right = new node<int>(5);
    root->right->right = new node<int>(5);
    ASSERT_EQ(count_unival_subtrees(root), 4);
    delete root;
}

TEST(BonusSolutionFixture, test_1) {
    node<int>* root = new node<int>(5);
    ASSERT_EQ(count_unival_subtrees_opt(root), 1);
    delete root;
}
TEST(BonusSolutionFixture, test_2) {
    node<int>* root = new node<int>(5);
    root->left = new node<int>(5);
    root->right = new node<int>(5);
    ASSERT_EQ(count_unival_subtrees_opt(root), 3);
    delete root;
}

TEST(BonusSolutionFixture, test_3) {
    node<int>* root = new node<int>(0);
    root->left = new node<int>(1);
    root->right = new node<int>(0);
    root->right->left = new node<int>(1);
    root->right->right = new node<int>(0);
    root->right->left->left = new node<int>(1); root->right->left->right = new node<int>(1);
    ASSERT_EQ(count_unival_subtrees_opt(root), 5);
    delete root;
}

TEST(BonusSolutionFixture, test_4) {
    node<int>* root = new node<int>(5);
    root->left = new node<int>(5);
    root->right = new node<int>(5);
    root->left->left = new node<int>(5);
    root->left->right = new node<int>(5);
    root->right->right = new node<int>(5);
    ASSERT_EQ(count_unival_subtrees_opt(root), 6);
    delete root;
}

TEST(BonusSolutionFixture, test_5) {
    node<int>* root = new node<int>(5);
    root->left = new node<int>(1);
    root->right = new node<int>(5);
    root->left->left = new node<int>(5);
    root->left->right = new node<int>(5);
    root->right->right = new node<int>(5);
    ASSERT_EQ(count_unival_subtrees_opt(root), 4);
    delete root;
}