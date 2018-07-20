// Copyright 2018 Akash Kwatra

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

// 018
// c strings
// Test out standard c string functions
// Print results of various c string functions and manipulations

int main() {
    cout << endl << "018 - c strings" << endl << endl;

    char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << "str[] = {'H', 'e', 'l', 'l', 'o', '\\0'}" << endl;
    cout << str << endl;
    cout << endl;
    cout << "Type in your name :: ";
    char name[20];
    cin.getline(name, sizeof(name));
    cout << str << " " << name << endl;
    cout << endl;
    cout << "strcat(\"" << name << "\", \"cat\") = "
         << strcat(name, "cat") << endl;
    cout << "strcmp(\"" << name << "\", \"cat\") = "
         << strcmp(name, "cat") << endl;
    cout << "strcmp(\"cat\", \"cat\") = " << strcmp("cat", "cat") << endl;
    cout << endl;
    cout << "&name = " << &name << endl;
    cout << "strstr(\"" << name << "\", \"cat\") = "
         << reinterpret_cast<int*>(strstr(name, "cat")) << endl;
    cout << endl;
    return 0;
}

