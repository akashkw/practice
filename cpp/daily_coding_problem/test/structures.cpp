#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <algorithm>

#include "structures.h"

using namespace std;

template <typename T>
int node<T>::depth() const {
    stack<pair<int, const node<T>*>> s;
    int max_depth = 0;
    s.push(make_pair(1, this));
    while(!s.empty()) {
        int depth = s.top().first;
        const node<T>* this_node = s.top().second;
        s.pop();
        if(max_depth < depth)
            max_depth = depth;
        if(this_node->left != nullptr) {
            s.push(make_pair(depth+1, this_node->left));
        }
        if(this_node->right != nullptr) {
            s.push(make_pair(depth+1, this_node->right));
        }
    }
    return max_depth;
}
    
/*
 15*               1
 7 *       1       15      2
 3 *   1       2   7   3       4
 1 * 1   2   3   4 3 5   6   7   8
 0 *1 2 3 4 5 6 7 819 0 1 2 3 4 5 6
*/
template <typename T>
node<T>::operator string() const {
    ostringstream output;
    queue<pair<int, node<T>*>> q;
    node<T>* root_copy = new node<T>(*this);
    q.push(make_pair(1, root_copy));
    int prev_level = 0; 
    int max_depth = depth();
    while(!q.empty()) {
        int level = q.front().first;
        node<T>* this_node = q.front().second;
        q.pop();
        if(level != prev_level) {
            output << "\n";
            for(int i = 0; i < ((2 << (max_depth-level)))-1; ++i)
                output << " ";
            ++prev_level;
        }
        if(this_node->valid) {
            output << this_node->data;
        }
        else {
            output << " ";
        }
        for(int i = 0; i < ((2<<((max_depth+1)-level))-1); ++i)
            output << " ";
        if(level != max_depth) {
            if (this_node->left == nullptr) {
                this_node->left = new node<T> (this_node->data, false);
            }
            if (this_node->right == nullptr) {
                this_node->right = new node<T> (this_node->data, false);
            }
            q.push(make_pair(level+1, this_node->left));
            q.push(make_pair(level+1, this_node->right));
        }
    }
    output << "\n";
    delete root_copy;
    return output.str();
}

