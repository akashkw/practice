// Copyright 2018 Akash Kwatra

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// 12
// inline sum
// Test out inline functions, as well as chrono
// Takes a number, calculates sum in different ways, reports times

int sum(int x, int y) {
    return x + y;
}

inline int inline_sum(int x, int y) {
    return x + y;
}

int main() {
    cout << endl << "12 - inline sum" << endl << endl;

    // TODO(akashkw): implement timer using chrono

    int x, y;
    cout << "Please enter first number :: ";
    cin >> x;
    cout << "Please enter second number :: ";
    cin >> y;

    cout << endl << "Expression :: sum is " << (x + y) << endl;
    cout << endl << "Inline Function :: sum is " << inline_sum(x, y) << endl;
    cout << endl << "Function ::  sum is " << sum(x, y) << endl;
    cout << endl;
    return ;
}

