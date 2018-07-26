// Copyright 2018 Akash Kwatra

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

// 32
// enhump day in class
// Test out enum class
// Loops through enum and lets you know when it's hump day

enum class Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main() {
    cout << endl << "32 - enhump day in class" << endl << endl;

    Day week[7] = {
        Day::Monday,
        Day::Tuesday,
        Day::Wednesday,
        Day::Thursday,
        Day::Friday,
        Day::Saturday,
        Day::Sunday
    };

    for (Day today : week) {
        if (today == Day::Wednesday) {
            cout << "It's Hump Day!!!!!!" << endl;
        } else {
            cout << "It's not hump day" << endl;
        }
    }

    cout << endl;

    return 0;
}

