#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<int> quicksort_helper(vector<int> list) {
    if(list.size() <= 1) {
        return list;
    }
    vector<int> smaller;
    vector<int> larger;
    for(int i = 1; i < list.size(); i++) {
        if(list[i] > list[0]) {
            larger.push_back(list[i]);
        }
        else {
            smaller.push_back(list[i]);
        }
    }
    vector<int> sorted;
    vector<int> sort_left = quicksort_helper(smaller);
    vector<int> sort_right = quicksort_helper(larger);
    sorted.insert(end(sorted), begin(sort_left), end(sort_left));
    sorted.push_back(list[0]);
    sorted.insert(end(sorted), begin(sort_right), end(sort_right));
    return sorted;
}

void quicksort(vector<int> &list) {
    list = quicksort_helper(list);
}

int main() {
    string test;
    while(getline(cin, test)) {
        stringstream input = stringstream(test);
        int i;
        vector<int> list;
        while(input >> i) {
            list.push_back(i);
        }
        cout << "List before sort" << endl;
        for(const int &v : list) {
            cout << v << " ";
        }
        cout << endl << endl;
        quicksort(list);
        cout << "List after sort" << endl;
        for(const int &v : list) {
            cout << v << " ";
        }
        cout << endl << endl;
    }
}
