#include <iostream>
using namespace std;

#define pl(n) cout << n << endl
    
int main() {
    int total_above_zero = 0;
    int num_temps;
    cin >> num_temps;
    for(int i = 0; i < num_temps; i++) {
        int tmp;
        cin >> tmp;
        if(tmp < 0) {
            total_above_zero++;
        }
    }
    
    pl(total_above_zero);
}
