// Copyright 2018 Akash Kwatra

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// 13
// make pointer
// Test out pointer initialization
// Takes in a number, creates a pointer to it

int main() {
    cout << endl << "13 - make pointer" << endl << endl;

    int x;
    cout << "Please enter a number (x) :: ";
    cin >> x;

    cout << endl << "Creating pointer (p) to your number (x)" << endl << endl;

    cout << "Size of int x is " << sizeof(int) << " bytes" << endl;
    cout << "Size of int *p is " << sizeof(int *) << " bytes" << endl;
    cout << endl;

    int *p = &x;

    cout << "x = " << x << endl;
    cout << "&x = " << &x << endl;
    cout << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "&p = " << &p << endl;
    cout << endl;
    cout << "*&p = " << *&p << endl;
    cout << "**&p = " << **&p << endl;

    cout << endl;
    return 0;
}

