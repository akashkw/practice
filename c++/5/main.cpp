// Copyright 2018 Akash Kwatra

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

// 005
// cmath
// Play around with cmath functions in cmath library
// Prints out various math functions and a use for each

int main() {
    cout << endl << "005 - cmath" << endl << endl;

    cout << "ceil(4.8) = " << ceil(4.8)
         << " and ceil(6.1) = " << ceil(6.1) << endl;
    cout << "fabs(4.8) = " << fabs(4.8)
         << " and fabs(-6.1) = " << fabs(-6.1) << endl;
    cout << "fmin(4.8, 6.1) = " << fmin(4.8, 6.1)
         << " and fmax(4.8, 6.1) = " << fmax(4.8, 6.1) << endl;
    cout << "pow(2, 3) = " << pow(2, 3)
         << " and pow(3, 3) = " << pow(3, 3) << endl << endl;

    return 0;
}

