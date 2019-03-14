
#ifndef test_helpers_h
#define test_helpers_h

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Return a string representation of a vector
template <typename T> string vec_string(const vector<T> &vec) {
    ostringstream out;
    out << "[";
    for(size_t i = 0; i < vec.size(); ++i)
        out << vec[i] << ",]"[i==vec.size()-1];
    return out.str();
}

#endif
