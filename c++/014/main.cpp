#include <iostream>

using namespace std;

// 014
// array memory
// Test out array memory allocation
// Takes in a number, creates a pointer to it

int main() {
    cout << endl << "014 - array memory" << endl << endl;

    int size;
    cout << "Enter the size of your array :: ";
    cin >> size;
    cout << endl;
    
    cout << "size = " << size << endl;
    cout << endl;

    int array[size];

    cout << "array = " << array << endl;
    
    // Populate array with values
    for(int i = 0; i < size; i++){
        array[i] = i * 2;
    }
    cout << endl;

    for(int i = 0; i < size; i++){
        cout << "array[" << i << "] = " << array[i];
        cout << "    |    &array[" << i << "] = " << &array[i] << endl;
    }

    int *p = array;
    cout << endl;
    cout << "p = " << p << endl;
    cout << endl;

    for(int i = 0; i < size; i++){
        cout << "*(p + " << i << ") = " << *(p+i);
        cout << "    |    (p + " << i << ") = " << (p+i) << endl;
    }

    cout << endl;
    return 0;
}

