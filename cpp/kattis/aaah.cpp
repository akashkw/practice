#include <iostream>
#include <string>
using namespace std;

#define pl(n) cout << n << endl
    
int main() {
    string jon, doctor;
    cin >> jon;
    cin >> doctor;
    
    pl(((doctor.length() > jon.length()) ? "no" : "go"));
}
