#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;
    
bool check_permutation_hash(const string &s1, const string &s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    unordered_map<char, int> hashmap;
    for (const char &c : s1) {
        hashmap[c]++;
    }
    for (const char &c : s2) {
        hashmap[c]--;
        if (hashmap[c] < 0) {
            return false;
        }
    }
    return true;
}

bool check_permutation_sort(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for ( int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string line;
    while(getline(cin, line)) {
        istringstream ss(line);
        string s1, s2;
        ss >> s1;
        ss >> s2;
        cout << s1 << " and " << s2 << " are permutations? :: "
             << boolalpha << check_permutation_hash(s1, s2) << endl;
        cout << s1 << " and " << s2 << " are permutations? :: "
             << boolalpha << check_permutation_sort(s1, s2) << endl;
        cout << endl;
    }
}
