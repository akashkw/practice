#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

/*
 * Problem Statement
 * This problem was asked by Google.
 * 
 * An XOR linked list is a more memory efficient doubly linked list. 
 * Instead of each node holding next and prev fields, it holds a field named both, 
 * which is an XOR of the next node and the previous node. 
 * 
 * Implement an XOR linked list; it has an add(element) which adds the element to the end, 
 * and a get(index) which returns the node at index.
 * 
 * If using a language that has no pointers (such as Python), you can assume
 * you have access to get_pointer and dereference_pointer functions 
 * that converts between nodes and memory addresses.
 */


TEST(SolutionFixture, test_1) {
    xor_linked_list<int> xll;
    xll.insert(2);
    ASSERT_EQ(xll.get(0), 2);
}


TEST(SolutionFixture, test_2) {
    xor_linked_list<int> xll;
    xll.insert(2);
    xll.insert(3);
    xll.insert(4);
    ASSERT_EQ(xll.get(2), 4);
}

TEST(SolutionFixture, test_3) {
    xor_linked_list<string> xll;
    xll.insert("hello");
    xll.insert("world");
    ASSERT_EQ(xll.get(1), "hello");
}

TEST(SolutionFixture, test_4) {
    xor_linked_list<string> xll;
    xll.insert("hello");
    xll.insert("world");
    ASSERT_EQ(xll.get(1), "hello");
}

TEST(SolutionFixture, test_4) {
    struct person {string name; int age;}
    xor_linked_list<person> xll;
    xll.insert({"akash", 21});
    xll.insert({"sue anne", 22});
    ASSERT_EQ(xll.get(0).name, "akash");
    ASSERT_EQ(xll.get(1).name, "sue anne");
    ASSERT_EQ(xll.get(0).age, 21);
    ASSERT_EQ(xll.get(1).age, 22);
}