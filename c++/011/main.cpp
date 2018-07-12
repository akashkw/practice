#include <iostream>
using namespace std;

// 011
// recursive factorial
// Test out functions and recursion
// Takes in a number, calculates the factorial of that number using recursion

int factorial(int x){
    if(x == 0 || x == 1){
        return 1;
    }
    return x * factorial(x-1);
}

int main() {
    cout << endl << "011 - recursive factorial" << endl << endl;
    
    int x;
    cout << "Please enter a number :: ";
    cin >> x;

    cout << endl << "Factorial of " << x << " is " << factorial(x) << endl;
    cout << endl;
    return 0;
}

