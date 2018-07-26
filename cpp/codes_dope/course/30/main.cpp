// Copyright 2018 Akash Kwatra

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// 30
// life is dynamic
// Test out destructors and dynamic memory
// Creates four boys dynamically allocated, then deletes them

class Boi {
    const string name;
 public:
    explicit Boi(const string name) : name(name) {
        cout << name << " has been born into this world!" << endl;
    }
    ~Boi() {
        if (name != "Nameless") {
            cout << name << " has been violently murdered!" << endl;
        }
    }
};

int main() {
    cout << endl << "30 - life is dynamic" << endl << endl;

    Boi *bois = new Boi[4] {
        Boi(string("Akash")),
        Boi(string("Benny")),
        Boi(string("Matt Damon")),
        Boi(string("Donald Trump"))
    };
    cout << endl;

    delete[] bois;

    cout << endl;
    return 0;
}

