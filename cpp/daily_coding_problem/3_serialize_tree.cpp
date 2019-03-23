#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <bitset>

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
    if (root == nullptr) {
        return "NULL ";
    }
    ostringstream serial;
    queue<pair<int, const node<T>*>> q;
    
    int null_counter = 0;
    q.push(make_pair(1, root));

    while(!q.empty()) {
        int depth = q.front().first; 
        const node<T>* current_node = q.front().second; 
        q.pop();
        const node<T>* left_node = nullptr; 
        const node<T>* right_node = nullptr; 
        if(current_node == nullptr) {
            ++null_counter;
            if(null_counter == 2<<(depth-2)) {
                break;
            }
        }
        else {
            while(null_counter > 0) {
                serial << "NULL ";
                --null_counter;
            }
            serial << current_node->data << " ";
            if(current_node->left != nullptr) {
                left_node = current_node->left;
            }
            if(current_node->right != nullptr) {
                right_node = current_node->right;
            }

        }
        q.push(make_pair(depth+1, left_node));
        q.push(make_pair(depth+1, right_node));
    }
    return serial.str();
}

template <typename T>
node<T>* deserialize(const string &serial) {
    istringstream input(serial);
    string token;
    node<T>* root = nullptr;
    input >> token;
    if(token == "NULL") {
        return root;
    }
    else {
        istringstream tokstream(token);
        T tok_T;
        tokstream >> tok_T;
        root = new node<T>(tok_T);
    }
    int depth = 0;
    int counter = 0;
    while(input >> token) {
        if(counter == (2<<depth)) {
            ++depth;
            counter = 0;
        }
        if(token != "NULL") {
            istringstream tokstream(token);
            T tok_T;
            tokstream >> tok_T;
            bitset<32> counter_bits(counter);        
            node<T>** current_node = &root;
            for(int i = 0; i < depth; ++i) {
                if(counter_bits.test(i)) {
                    current_node = &((*current_node)->right);
                }
                else {
                    current_node = &((*current_node)->left);
                }
            }
            *current_node = new node<T>(tok_T);

        }
        ++counter;
    }
    return root;
}

TEST(SolutionFixture, test_1) {
    node<int>* root = new node<int>(1);
    root->left = new node<int>(3);
    root->right = new node<int>(5);
    ASSERT_EQ(serialize(root), "1 3 5 ");
    delete root;
}
TEST(SolutionFixture, test_2) {
    node<int>* root = new node<int>(1);
    root->left = new node<int>(3);
    root->right = new node<int>(5);
    root->left->left = new node<int>(12);
    root->left->right = new node<int>(8);
    root->right->right = new node<int>(9);
    ASSERT_EQ(serialize(root), "1 3 5 12 8 NULL 9 ");
    delete root;
}
TEST(SolutionFixture, test_3) {
    node<int>* root = new node<int>(1);
    root->left = new node<int>(3);
    root->right = new node<int>(5);
    root->left->left = new node<int>(12);
    root->left->right = new node<int>(8);
    root->right->right = new node<int>(9);
    root->right->right->left = new node<int>(34);
    ASSERT_EQ(serialize(root), "1 3 5 12 8 NULL 9 NULL NULL NULL NULL NULL NULL 34 ");
    delete root;
}

TEST(SolutionFixture, test_4) {
    node<int>* root = new node<int>(1);
    root->left = new node<int>(3);
    root->right = new node<int>(5);

    node<int>* new_root = deserialize<int>("1 3 5 ");
    ASSERT_EQ(*root, *new_root);
    delete root;
    delete new_root;
}
TEST(SolutionFixture, test_5) {
    node<int>* root = new node<int>(1);
    root->left = new node<int>(3);
    root->right = new node<int>(5);
    root->left->left = new node<int>(12);
    root->left->right = new node<int>(8);
    root->right->right = new node<int>(9);
    node<int>* new_root = deserialize<int>("1 3 5 12 8 NULL 9 ");
    ASSERT_EQ(*root, *new_root);
    delete root;
    delete new_root;
}
TEST(SolutionFixture, test_6) {
    node<int>* root = new node<int>(1);
    root->left = new node<int>(3);
    root->right = new node<int>(5);
    root->left->left = new node<int>(12);
    root->left->right = new node<int>(8);
    root->right->right = new node<int>(9);
    root->right->right->left = new node<int>(34);
    node<int>* new_root = deserialize<int>("1 3 5 12 8 NULL 9 NULL NULL NULL NULL NULL NULL 34 ");
    ASSERT_EQ(*root, *new_root);
    delete root;
    delete new_root;
}
