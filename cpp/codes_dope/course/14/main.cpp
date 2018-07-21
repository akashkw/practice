// Copyright 2018 Akash Kwatra

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// 14
// array memory
// Test out array memory allocation
// Takes in a number, creates a pointer to it

int main() {
    cout << endl << "14 - array memory" << endl << endl;

    int kSize;

    cout << "Enter the size of your array :: ";
    cin >> kSize;
    cout << endl;
    cout << "kSize = " << kSize << endl;
    cout << endl;

    int *array = new int[kSize];
    cout << "array = " << array << endl;

    // Populate array with values
    for (int i = 0; i < kSize; i++) {
        array[i] = i * 2;
    }
    cout << endl;

    for (int i = 0; i < kSize; i++) {
        cout << "array[" << i << "] = " << array[i];
        cout << "    |    &array[" << i << "] = " << &array[i] << endl;
    }

    int *p = array;
    cout << endl;
    cout << "p = " << p << endl;
    cout << endl;

    for (int i = 0; i < kSize; i++) {
        cout << "*(p + " << i << ") = " << *(p+i);
        cout << "    |    (p + " << i << ") = " << (p+i) << endl;
    }

    cout << endl;
    return 0;
}

