#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

#include "test/structures.h"

using namespace std;

/*
 * Problem Statement
 *
 */

// Solution Function
bool solution(int num) {
    return num;
}

TEST(SolutionFixture, test_1) {

    node<int>* root = new node<int>(1);
    root->left = new node<int>(2);
    root->right = new node<int>(3);
    root->left->left = new node<int>(4);
    root->left->right = new node<int>(5);
    root->right->left = new node<int>(6);
    root->right->right = new node<int>(7);
    root->left->left->left = new node<int>(8);
    root->left->left->right = new node<int>(9);
    root->right->left->left = new node<int>(1);
    root->right->left->right = new node<int>(2);

    node<int>* root_2 = new node<int>(*root);
    
    cout << root->depth() << endl;
    cout << (*root==*root_2) << endl;
    root->right->left->right = new node<int>(7);
    cout << root << endl;
    cout << root_2 << endl;

    cout << *root << endl;
    cout << (*root==*root_2) << endl;

    ASSERT_TRUE(solution(1));
    delete root;
    delete root_2;
}

