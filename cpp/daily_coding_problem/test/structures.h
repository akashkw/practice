
#ifndef test_structures_h
#define test_structures_h

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
struct node {

    T data;
    node* left;
    node* right;

    node() : left(nullptr), right(nullptr) {}
    node(T& d) : data(d), left(nullptr), right(nullptr) {}
    node(T& d, node* l, node* r): data(d), left(l), right(r) {}
}

#endif
