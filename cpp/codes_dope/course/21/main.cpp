// Copyright 2018 Akash Kwatra

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// 21
// struct bois
// Test out the creation and usage of structs
// Create a and array of boi structs and print them out

struct boi {
    int age;
    string name;
    string phone_number;
};

void print_boi(const struct boi &this_boi) {
    cout << "You can find this boi at " << &this_boi << endl;

    cout << "This boi's name is " << this_boi.name << endl
         << "He is " << this_boi.age << " years old" << endl
         << "His phone number is " << this_boi.phone_number
         << endl << endl;
}

int main() {
    cout << endl << "21 - basic define" << endl << endl;

    struct boi bois[3];
    bois[0] = {20, "Akash Kwatra", "512-423-9293"};
    bois[1] = {15, "Eshan Kwatra", "512-695-4035"};
    bois[2] = {51, "Ajay Kwatra", "512-560-9976"};

    cout << "One boi takes up " << sizeof(struct boi) << " bytes"
         << endl << endl;

    for (const struct boi &this_boi : bois) {
        print_boi(this_boi);
    }
    return 0;
}

