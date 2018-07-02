#include <iostream>
using namespace std;

// 004
// Test of implicit cast of char to int and explicit cast back to char
// Reads in number and character, prints out character shifted by number

int main() {
    int n;
    char c;
    cout << "Please enter a character" << endl;
    cin >> c;
    cout << "Please enter how much to shift it by" << endl;
    cin >> n;
    cout << "Your character is " << (char)(n + c) << endl;
    return 0;
}

