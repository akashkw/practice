#include <iostream>
using namespace std;

// 003
// char shifter
// Test of implicit cast of char to int and explicit cast back to char
// Reads in number and character, prints out character shifted by number

int main() {
    cout << endl << "003 - char shifter" << endl << endl;
    int n;
    char c;
    cout << "Please enter a character :: ";
    cin >> c;
    cout << "Please enter how much to shift it by :: ";
    cin >> n;
    cout << endl << "Your character is :: " << (char)(n + c) << endl << endl;
    return 0;
}

