// Copyright 2018 Akash Kwatra

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// 7
// grade checker
// Test out swtich statements
// Takes in a character as a grade letter, prints out meaning

int main() {
    cout << endl << "7 - grade checker" << endl << endl;

    char c;
    cout << "Please enter your grade :: ";
    cin >> c;
    cout << endl;
    switch (c) {
        case 'A': case 'a':
            cout << "You did excellent";
            break;
        case 'B': case 'b':
            cout << "Pretty good";
            break;
        case 'C': case 'c':
            cout << "Just barely made it";
            break;
        case 'F': case 'f':
            cout << "You failed";
            break;
        default:
            cout << "That's not a valid grade letter";
    }
    cout << endl << endl;
    return ;
}

