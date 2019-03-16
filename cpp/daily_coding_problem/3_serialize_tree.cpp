#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#include "gtest/gtest.h"

#include "test/structures.h"

using namespace std;

/*
 * Problem Statement
 *
 * This problem was asked by Google.
 * Given the root to a binary tree, implement serialize(root), 
 * which serializes the tree into a string, and deserialize(s), 
 * which deserializes the string back into the tree.
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
template <typename T>
string serialize(const node<T>* root) {
    ostringstream str, tree;
    queue<pair<int, const node<T>*>> q;
    int depth = 0;
    q.push(make_pair(1, root));

    while(!q.empty()) {
        int level = q.front().first;
        const node<T>* this_node= q.front().second;
        q.pop();
        if(level > depth) depth = level;
        tree << this_node->data << ",";
        if(this_node->left != nullptr) {
            q.push(make_pair(level+1, this_node->left)); 
        }
        if(this_node->right != nullptr) {
            q.push(make_pair(level+1, this_node->right)); 
        }
    }
    str << depth << " " << tree.str();
    return str.str();
}

TEST(SolutionFixture, test_1) {
    node<int>* root = new node<int>(1, new node<int>(1), new node<int>(2));
    cout << root << endl;
    ASSERT_EQ(serialize(root), "2 1,1,2,");
}

