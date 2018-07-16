// Copyright 2018 Akash Kwatra

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// 006
// even odd
// Test out if statements and modulus
// Takes in a number, prints out if even or odd

int main() {
    cout << endl << "006 - even odd" << endl << endl;

    int n;
    cout << "Please enter a number :: ";
    cin >> n;
    cout << endl;
    if ( n%2 == 0 ) {
        cout << n << " is even";
    } else {
        cout << n << " is odd";
    }
    cout << endl << endl;
    return 0;
}

