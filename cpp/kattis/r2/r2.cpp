#include <iostream>
using namespace std;

#define pl(n) cout << n << endl
    
int main() {
    int num1, avg;
    cin >> num1;
    cin >> avg;

    pl(avg + (avg-num1));
}
