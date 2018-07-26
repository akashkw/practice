// Copyright 2018 Akash Kwatra

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

// 31
// enhump day
// Test out simple enum
// Loops through enum and lets you know when it's hump day

enum Days {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main() {
    cout << endl << "31 - enhump day" << endl << endl;

    for (int today = Monday; today <= Sunday; today++) {
        if (today == Wednesday) {
            cout << "It's Hump Day!!!!!" << endl;
        } else {
            cout << "It's not hump day" << endl;
        }
    }

    cout << endl;
    return 0;
}

