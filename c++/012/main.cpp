#include <iostream>
#include <ctime>

using namespace std;

// 012
// inline sum
// Test out inline functions, as well as ctime
// Takes in a number, calculates sum with and without an inline function, reports times

inline int sum(int x, int y){
    return x + y;
}

int main() {
    cout << endl << "012 - inline sum" << endl << endl;
    
    int x, y;
    cout << "Please enter first number :: ";
    cin >> x;
    cout << "Please enter second number :: ";
    cin >> y;

    cout << endl << "Sum is " << (x + y) << endl;
    cout << endl;
    return 0;
}

