// Copyright 2018 Akash Kwatra

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// 26
// a little too friendly
// Test out friend functions and encapsulation
// Creates Bob and three Girls, Bob shares their secrets

class Girl;

class Bob {
 public:
     Bob() {
        cout << "Bob likes to gossip and knows many secrets" << endl;
        cout << "Lets share some of them" << endl << endl;
     }
     void gossip(Girl);
};

class Girl {
    string dark_secret;
 public:
    string name;
    Girl(string name, string ds) : name(name), dark_secret(ds) {}
    friend void Bob::gossip(Girl);
};

void Bob::gossip(Girl g) {
    cout << g.name << "'s secret is " << g.dark_secret << endl;
}

int main() {
    cout << endl << "26 - a little too friendly " << endl << endl;
    Girl alice = Girl("Alice", "she likes pineapple pizza");
    Girl lisa = Girl("Lisa", "she has a secret obsession with peanut butter");
    Girl jessica = Girl("Jessica", "well, trust me you don't wanna know");
    Bob b = Bob();
    b.gossip(alice);
    b.gossip(lisa);
    b.gossip(jessica);
    cout << endl;
    return 0;
}

