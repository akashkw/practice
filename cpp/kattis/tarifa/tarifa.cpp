#include <iostream>
using namespace std;

#define pl(n) cout << n << endl
    
int main() {
    int total_megs, months;
    int total_accumulated = 0;
    cin >> total_megs;
    cin >> months;

    for(int i = 0; i < months; i++) {
        int tmp;
        cin >> tmp;
        total_accumulated += (total_megs - tmp);
    }

    pl(total_accumulated + total_megs);
}
