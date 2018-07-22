// Copyright 2018 Akash Kwatra

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// 24
// casper the multifaceted doggo
// Test out subclasses and multiple inheritance
// Creates a fast dog named Capser and performs various functions

class Fast {
 public:
    Fast() {
    cout << "This looks like it's fast!" << endl;
    }
    void zoomies(){
        cout << "Zoom Zoom! Weeeeeeeeeeeeeeeeee!" << endl;
    }
};

class Doggo {
 public:
    Doggo() {
    cout << "This looks like a doggo!" << endl;
    }
    void bork(){
        cout << "Bork Bork! Grrrrrrrrrrrrrrrrrr!" << endl;
    }
};

class Casper : public Doggo, public Fast {
 public:
     Casper() {
        cout << "This looks like it's Casper!" << endl;
     }
     void eat_ice_cubes(){
         cout << "Crunch Crunch Crunch, mmmmm yummy ice cubes!" << endl;
     }
};

int main() {
    cout << endl << "23 - casper the multifaceted doggo" << endl << endl;
    Casper casper;
    cout << endl;

    casper.bork();
    casper.zoomies();
    casper.eat_ice_cubes();

    cout << endl;
    return 0;
}

