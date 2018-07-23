// Copyright 2018 Akash Kwatra

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ios;

// 27
// numberfile
// Test out file io, random numbers, and system calls
// Print out 100 random numbers to a file, read them, delete file

int main() {
    cout << endl << "27 - numberfile" << endl << endl;

    uint32_t seed = time(NULL);

    ofstream o_file;
    o_file.open("numberfile.txt");
    o_file << "These are my favorite numberfile numbers" << endl;
    for (int i = 0; i < 10; i++) {
        o_file << ((rand_r(&seed) % 1000) + 1) << endl;
    }
    o_file.close();

    string output;
    ifstream i_file;
    i_file.open("numberfile.txt");
    getline(i_file, output);
    cout << output << endl << endl;
    for (int i = 0; i < 10; i++) {
        i_file >> output;
        cout << output << endl;
    }
    i_file.close();

    system("rm numberfile.txt");

    cout << endl;
    return 0;
}

