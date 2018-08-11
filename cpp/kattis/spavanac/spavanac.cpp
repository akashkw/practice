#include <iostream>
using namespace std;

#define pl(n) cout << n << endl
    
int main() {
    int hours, minutes;
    cin >> hours;
    cin >> minutes;

    if(minutes >= 45) {
        minutes -= 45;
    }
    else {
        minutes = (60 - (45 - minutes));
        if(hours == 0) {
            hours = 23;
        }
        else {
            hours--;
        }
    }
    
    pl(hours << " " << minutes);
}
