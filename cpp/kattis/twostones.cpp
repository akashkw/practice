#include <iostream>
using namespace std;

#define pl(n) cout << n << endl
    
int main() {
    int stonecount;
    cin >> stonecount;
    
    pl(((stonecount % 2 == 0) ? "Bob" : "Alice"));
}
