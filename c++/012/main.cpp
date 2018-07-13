#include <iostream>
#include <chrono>

using namespace std;

// 012
// inline sum
// Test out inline functions, as well as chrono
// Takes in a number, calculates sum with and without an inline function, reports times

int sum(int x, int y){
    return x + y;
}

inline int inline_sum(int x, int y){
    return x + y;
}

int main() {
    cout << endl << "012 - inline sum" << endl << endl;

    // TODO implement timer using chrono
    
    int x, y;
    cout << "Please enter first number :: ";
    cin >> x;
    cout << "Please enter second number :: ";
    cin >> y;

    cout << endl << "Expression :: sum is " << (x + y) << endl;
    cout << endl << "Inline Function :: sum is " << inline_sum(x, y) << endl;
    cout << endl << "Function ::  sum is " << sum(x, y) << endl;
    cout << endl;
    return 0;
}

