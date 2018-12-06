// This problem was asked by Uber.

// Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

// For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

// Follow-up: what if you can't use division?

#include <iostream>
#include <vector>
using namespace std;

vector<int> product_array(const vector<int> &input) {
    vector<int> left(input.size(), 1);
    vector<int> right(input.size(), 1);
    vector<int> product(input.size(), 1);
    for(int i = 1; i < input.size(); i++) {
        left[i] = left[i-1] * input[i-1];
        right[input.size()-i-1] = right[input.size()-i] * input[input.size()-i];
    }
    for(int i = 0; i < input.size(); i++) {
        product[i] = left[i] * right[i];
    }
    return product;
}

int main() {
    vector<vector<int>> tests = { {1, 2, 3, 4, 5},
                                  {3, 2, 1} };
    for(const vector<int> &test : tests) {
        for(int i : product_array(test)) cout << i << " ";
        cout << endl;
    }
}
