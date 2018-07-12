#include <iostream>
using namespace std;

// 008
// ternary even odd
// Test out ternary operators
// Takes in a number, prints out if even or odd, uses ternary operators

int main() {
    cout << endl << "008 - ternary even odd" << endl << endl;

    int n;
    cout << "Please enter a number :: ";
    cin >> n;
    cout << endl;
    ( n%2 == 0 ) ? cout << n << " is even" : cout << n << " is odd";
    cout << endl << endl;
    return 0;
}

