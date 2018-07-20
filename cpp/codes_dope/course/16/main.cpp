// Copyright 2018 Akash Kwatra

#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::sort;

// 016
// array iterators
// Test out iterator functionality
// Fills an array with 2's, prints out values

void printArray(const array<int, 5> &n) {
    cout << "Printed values of array" << endl << endl;
    for (int j = 0; j < n.size(); j++) {
        cout << "n[" << j << "] = " << n[j] << endl;
    }
    cout << endl;
}

int main() {
    cout << endl << "016 - array iterators" << endl << endl;

    array<int, 5> n = { 6, 4, 2, 10, 8};
    printArray(n);

    cout << "n.begin() = " << n.begin() << endl;
    cout << "n.end() = " << n.end() << endl;
    cout << endl;
    for (auto i = n.begin(); i != n.end(); i++) {
        cout << "i = " << i << "    |    " << "i* = " << *i << endl;
    }

    cout << endl;
    cout << "sort(n.begin(), n.end())" << endl;
    sort(n.begin(), n.end());
    printArray(n);

    return 0;
}

