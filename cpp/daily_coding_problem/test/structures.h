
#ifndef test_structures_h
#define test_structures_h

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <algorithm>

using namespace std;

template <typename T>
struct node {

    T data;
    node* left;
    node* right;
    bool valid;

    node() : left(nullptr), right(nullptr), valid(true) {}
    node(const T& d) : data(d), left(nullptr), right(nullptr), valid(true) {}
    node(const T& d, node* l, node* r): data(d), left(l), right(r), valid(true) {}
    node(const node<T> &other) : data(other.data), left(nullptr), right(nullptr), valid(true) {
        left = other.left == nullptr ? nullptr : new node(*(other.left));
        right = other.right == nullptr ? nullptr : new node(*(other.right));
    }
    node(const T &d, const bool &valid) : data(d), left(nullptr), right(nullptr), valid(valid) {}
    node& operator=(const node<T> &other) {
        data = other.data;
    }
    ~node() {
        delete left, left = nullptr;
        delete right, right = nullptr;
    }

    int depth() const; 

    operator string() const;
};

#include "structures.cpp"

#endif
