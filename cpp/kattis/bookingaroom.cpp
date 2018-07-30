#include <iostream>
#include <vector>
using namespace std;

#define pl(n) cout << n << endl
    
int main() {

    int numrooms, numbooked;
    cin >> numrooms;
    cin >> numbooked; 

    vector<int> booked(numbooked);
    for(int i = 0; i < numbooked; i++) {
        int tmp;
        cin >> tmp;
        booked[i] = tmp;
    }
    for(int i = 1; i <= numrooms; i++) {
        bool found = false;
        for(int j : booked) {
            if(j == i) {
                found = true;
            }
        }
        if(!found) {
            pl(i);
            return 0;
        }
    }
    pl("too late");
}
