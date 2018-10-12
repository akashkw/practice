#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int fact_trail_zero(int n) {
    int count = 0;
    int exp = 20;
    while(--exp > 0) {
        if(n >= pow(5, exp)) {
            int x = n;
            while(x > 0) {
                count++;
                x -= pow(5, exp);
            }
        }
    }
    return count;
}

int main() {
    int n;
    while(cin >> n) {
        cout << fact_trail_zero(n) << endl;
    }
}
