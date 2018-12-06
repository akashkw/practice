// This problem was recently asked by Google.

// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

// Bonus: Can you do this in one pass?

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool two_sum(const vector<int> &list, const int &k) {

    unordered_set<int> seen;
    for (const int &i : list) {
        if(seen.find(k-i) == seen.end()) {
           seen.insert(i); 
           continue;
        }
        return true;
    }
    return false;
}

int main() {

    int k = 17;
    vector<int> list = {10, 15, 3, 7};
    cout << two_sum(list, k) << endl;

}
