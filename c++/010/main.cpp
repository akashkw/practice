// Copyright 2018 Akash Kwatra

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// 010
// infinite respect
// Test out infinite loops and breaks
// Prints out "press F to pay respects" repeatedly until F is entered

int main() {
    cout << endl << "010 - infinite respect" << endl << endl;

    char x;
    for ( ; ; ) {
       cout << "press F to pay respects" << endl;
       cin >> x;
       if (x == 'F' || x == 'f') {
           break;
       }
    }
    cout << endl << "thank you" << endl;
    cout << endl;
    return 0;
}

