// Copyright 2018 Akash Kwatra

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// 009
// loop test
// Test out for and while loops
// Takes in a number n, prints out 1 through n using for and while loops

int main() {
    cout << endl << "009 - loop test" << endl << endl;

    int n;
    cout << "Please enter a number :: ";
    cin >> n;
    cout << endl << endl;

    cout << "For Loop Test" << endl << endl;
    for (int i = 0; i <= n; i++) {
        cout << i << endl;
    }
    cout << endl;

    cout << "While Loop Test" << endl << endl;
    int w = 0;
    while (w <= n) {
        cout << w << endl;
        w++;
    }

    cout << endl;
    return 0;
}

