// Copyright 2018 Akash Kwatra

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// 28
// templatree
// Test out use of templates, inline ternary operators
// Takes in a value, float, int, or other, and prints out a tree

inline int set_odd(int i) {
    return (i%2 == 0) ? i + 1 : i;
}

template < typename T >
void print_tree(T height_t) {
    int height = set_odd(static_cast<int>(height_t));
    int tree_width = 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < (height - tree_width) / 2; j++) {
            cout << ' ';
        }
        for (int j = 0; j < tree_width; j++) {
            cout << '=';
        }
        for (int j = 0; j < (height - tree_width) / 2; j++) {
            cout << ' ';
        }
        if (i == tree_width) {
            tree_width += 2;
        }
        cout << endl;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < height; j++) {
            if (j == (height/2)) {
                cout << '=';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

int main() {
    cout << endl << "28 - templatree" << endl << endl;

    print_tree(13);
    cout << " height = 13" << endl;
    cout << endl;

    print_tree(12.5);
    cout << "height = 12.5" << endl;
    cout << endl;
    return 0;
}

