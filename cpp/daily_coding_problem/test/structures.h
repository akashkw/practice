
#ifndef test_structures_h
#define test_structures_h

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

template <typename T>
struct node {

    T data;
    node* left;
    node* right;

    node() : left(nullptr), right(nullptr) {}
    node(const T& d) : data(d), left(nullptr), right(nullptr) {}
    node(const T& d, node* l, node* r): data(d), left(l), right(r) {}
    node(const node<T> &other) : data(other.data) {
        left = other.left == nullptr ? nullptr : new node(*(other.left));
        right = other.right == nullptr ? nullptr : new node(*(other.right));
    }
    node& operator=(const node<T> &other) {
        data = other.data;
    }
    ~node() {
        delete left, left = nullptr;
        delete right, right = nullptr;
    }
    operator string() {
        ostringstream output;
        queue<pair<int, node<T>>> q;
        q.push(make_pair(0, *this));
        int prev_level = 0; 
        while(!q.empty()) {
            int level = q.front().first;
            node<T> this_node = q.front().second;
            q.pop();
            if(level != prev_level) {
                output << "\n";
                ++prev_level;
            }
            output << this_node.data << " ";
            if(this_node.left != nullptr) {
                q.push(make_pair(level+1, *(this_node.left)));
            }
            if(this_node.right != nullptr) {
                q.push(make_pair(level+1, *(this_node.right)));
            }
        }
        output << "\n";
        return output.str();
    }
};

#endif
