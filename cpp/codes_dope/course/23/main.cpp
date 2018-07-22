// Copyright 2018 Akash Kwatra

#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::transform;

// 23
// subclass pets
// Test out subclasses, as well as transform and init lists
// Creates three animals and prints out information about them

class Animal {
 protected:
    string name;
    string color;
 public:
    Animal(string name, string color) {
        transform(name.begin(), name.end(), name.begin(), tolower);
        transform(color.begin(), color.end(), color.begin(), tolower);
        this->name = name;
        this->color = color;
    }
    void print_info(){
        cout << "This is a " << color << " animal named " << name << endl;
    }
};

class Doggo : public Animal {
 public:
    Doggo(string name, string color) : Animal(name, color) { }
    void print_info(){
        cout << "This is a " << color << " doggo named " << name << endl;
    }
};

class Cat : public Animal {
 public:
    Cat(string name, string color) : Animal(name, color) { }
    void print_info(){
        cout << "This is a " << color << " cat named " << name << endl;
    }
};

int main() {
    cout << endl << "23 - subclass pets" << endl << endl;
    Animal sonic("Sonic", "Blue");
    Doggo clifford("Clifford", "Red");
    Cat garfield("Garfield", "Orange");

    sonic.print_info();
    clifford.print_info();
    garfield.print_info();

    cout << endl;
    return 0;
}

