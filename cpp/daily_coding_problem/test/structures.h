
#ifndef test_structures_h
#define test_structures_h

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
struct Node {

    T data;
    Node* left;
    Node* right;

    Node() = default;
    Node(T& d) : data(d) {}
    Node(T& d, Node* l, Node* r): data(d), left(l), right(r) {}
}

#endif
