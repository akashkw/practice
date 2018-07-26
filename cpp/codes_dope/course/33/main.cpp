// Copyright 2018 Akash Kwatra

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// 33
// goldfish union
// Test out unions
// Take in various values for a boy, print them back out

union boi {
    char name[40];
    int age;
    char fav_color[20];
};

int main() {
    union boi akash;
    cout << endl << "33 - goldfish union" << endl << endl;
    cout << "Hi! it's nice to meet you!" << endl;
    cout << "Tell me about yourself, also sorry in advance" << endl;
    cout << "I happen to have the memory of a goldfish" << endl;
    cout << endl;
    cout << "So, what's your name? :: ";
    cin.getline(akash.name, 40);
    cout << "Ah so your name is " << akash.name << endl << endl;
    cout << "How old are you " << akash.name << "? :: ";
    cin >> akash.age;
    cin.ignore();
    cout << "Oh neat, so you're " << akash.age << " years old!" << endl;
    cout << endl;
    cout << "What's your favorite color? :: ";
    cin.getline(akash.name, 40);
    cout << "Hey my favorite color is also "
         << akash.fav_color << "!" << endl << endl;
    cout << "So, let me see if I got all this... " << endl;
    cout << "Your name is " << akash.name << endl;
    cout << "You are " << akash.age << " years old" << endl;
    cout << "And your favorite color is " << akash.fav_color << endl;
    cout << endl;
    cout << "I think I got it all, nice meeting you " << akash.name << endl;
    cout << endl;

    return 0;
}

