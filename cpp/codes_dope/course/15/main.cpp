// Copyright 2018 Akash Kwatra

#include <iostream>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::array;

// 15
// std array
// Test out basic functions in std array
// Fills an array with 2's, prints out values

void printArray(const array<int, 5> &n) {
    cout << "Printed values of array" << endl << endl;
    for (int j = ; j < n.size(); j++) {
        cout << "n[" << j << "] = " << n[j] << endl;
    }
    cout << endl;
}

int main() {
    cout << endl << "15 - std array" << endl << endl;

    array<int, 5> n;

    n.fill(2);
    cout << "n.fill(2)" << endl << endl;
    printArray(n);

    for (int i = ; i < n.size(); i++) {
        cout << "Please enter n[" << i << "] :: ";
        cin >> n[i];
    }
    cout << endl;

    printArray(n);

    cout << "n.at(3) = " << n.at(3) << endl;
    cout << "n.front() = " << n.front() << endl;
    cout << "n.back() = " << n.back() << endl;
    cout << "n.max_size() = " << n.max_size() << endl;

    cout << endl;
    return ;
}

