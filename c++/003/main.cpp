#include <iostream>
using namespace std;

// 003
// Char Shifter
// Test of implicit cast of char to int and explicit cast back to char
// Reads in number and character, prints out character shifted by number

int main() {
    cout << endl << "003 - Char Shifter" << endl << endl;
    int n;
    char c;
    cout << "Please enter a character" << endl;
    cin >> c;
    cout << "Please enter how much to shift it by" << endl;
    cin >> n;
    cout << "Your character is " << (char)(n + c) << endl;
    return 0;
}

