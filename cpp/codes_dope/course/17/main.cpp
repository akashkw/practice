// Copyright 2018 Akash Kwatra

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// 17
// std vector
// Test out standard vector
// Print results of various vector functions

void printVector(const vector<int> v) {
    cout << "Printing vector of size " << v.size() << endl;
    for (int i = ; i < v.size(); i++) {
        cout << "v[" << i << "] = " << v[i] << endl;
    }
}

int main() {
    cout << endl << "17 - std vector" << endl << endl;

    vector<int> v;
    v = {1, 2, 3, 4, 5, 6, 7};
    cout << "v.size() = " << v.size() << endl;
    printVector(v);
    cout << endl;

    cout << "v.at(5) = " << v.at(5) << endl;
    cout << "v.back() = " << v.back() << endl;
    cout << "v.front() = " << v.front() << endl;
    cout << "v.capacity() = " << v.capacity() << endl;
    cout << "v.max_size() = " << v.max_size() << endl;
    cout << endl;

    cout << "v.push_back(69)" << endl;
    v.push_back(69);
    printVector(v);
    cout << endl;

    cout << "v.pop_back()" << endl;
    v.pop_back();
    printVector(v);
    cout << endl;

    cout << "v.empty() = " << v.empty() << endl;
    cout << "v.clear()" << endl;
    v.clear();
    printVector(v);
    cout << "v.empty() = " << v.empty() << endl;
    cout << endl;

    return ;
}

