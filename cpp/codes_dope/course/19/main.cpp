// Copyright 2019 Akash Kwatra

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

// 19
// std strings
// Test out standard cpp strings
// Read in name, perform various operations on strings

int main() {
    cout << endl << "19 - std strings" << endl << endl;

    cout << "Please enter your name :: ";
    string name;
    getline(cin, name);
    cout << "name = " << name << endl;
    cout << endl;
    cout << "name.length() = " << name.length() << endl;
    cout << "name.size() = " << name.size() << endl;
    name.resize(name.size() + 4, '*');
    cout << "name.resize(name.size() + 4, '*') = " << name << endl;
    cout << endl;
    cout << "name.empty() = " << name.empty() << endl;
    cout << "name.clear()" << endl;
    name.clear();
    cout << "name.empty() = " << name.empty() << endl;
    cout << endl;
    cout << "name = \"testing\"" << endl;
    name = "testing";
    cout << "name[4] = " << name[4] << endl;
    cout << "name.at(4) = " << name.at(4) << endl;
    cout << endl;
    cout << "name.compare(string(\"hello\")) = "
         << name.compare(string("hello")) << endl;
    cout << "name.compare(string(\"testing\")) = "
         << name.compare(string("testing")) << endl;
    cout << endl;
    cout << "name.find('i') = " << name.find('i') << endl;
    cout << "name.substr(2, 5) = " << name.substr(2, 4) << endl;
    cout << endl;
    return 0;
}

