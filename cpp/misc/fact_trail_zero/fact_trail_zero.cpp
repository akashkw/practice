#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int fact_trail_zero(int n) {
    int factor = 5;
    int count = 0;
    while(n/factor >= 1) {
        count += n / factor;
        factor *= 5;
    }
    return count;
}

int main() {
    int n;
    while(cin >> n) {
        cout << fact_trail_zero(n) << endl;
    }
}
