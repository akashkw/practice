#include <iostream>
#include <string>
#include <unordered_set>
#include <bitset>
#include <algorithm>
using namespace std;
    
bool isunique_hash(const string &str) {
    unordered_set<char> hashset;
    for(const char &c : str) {
        if(hashset.find(c) != hashset.end()) {
            return false;
        }
        else {
            hashset.insert(c);
        }
    }
    return true;
}

bool isunique_bits(const string &str) {
    bitset<256> ascii;
    for(const char &c : str) {
        if (ascii.test(c)) {
            return false;
        }
        else {
            ascii.set(c);
        }
    }
    return true;
}

bool isunique_sort(const string &str) {
    string strcpy = str.c_str();
    sort(strcpy.begin(), strcpy.end());
    for (int i = 0; i < strcpy.size() - 1; i++) {
        if (strcpy[i] == strcpy[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string line;
    while(getline(cin, line)) {
        cout << line << " is unique? :: " << boolalpha << isunique_hash(line) << endl;
        cout << line << " is unique? :: " << boolalpha << isunique_bits(line) << endl;
        cout << line << " is unique? :: " << boolalpha << isunique_sort(line) << endl;
        cout << endl;
    }
}
