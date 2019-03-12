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

    node<string>* root = new node<string>("root", new node<string>("rootl"), new node<string>("rootr"));
    root->left->left = new node<string>("rootll");
    root->left->right = new node<string>("rootlr");
    root->right->right = new node<string>("rootrr");
    root->right->right->left = new node<string>("rootrrl");
    cout << root->data << endl;

    root->print();
    delete root;

    ASSERT_TRUE(solution(1));
}

