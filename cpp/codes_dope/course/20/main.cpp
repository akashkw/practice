// Copyright 2018 Akash Kwatra

#include <iostream>

#define PI 3.14
#define average(a, b) ((a + b) / 2)

using std::cout;
using std::cin;
using std::endl;

// 20
// basic define
// Test out some simple define statements
// Print out PI, read in two numbers and print average

int main() {
    cout << endl << "20 - basic define" << endl << endl;

    cout << "PI = " << PI << endl;
    cout << endl;

    int a, b;
    cout << "Please enter first number :: ";
    cin >> a;
    cout << "Please enter seond number :: ";
    cin >> b;
    cout << endl;

    cout << "average(a, b) = " << average(a, b) << endl;

    cout << endl;
    return 0;
}

