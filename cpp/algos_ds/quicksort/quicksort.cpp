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
    int num_tests;
    cin >> num_tests;
    for(int i = 1; i <= num_tests; i++) {
        string line;
        cin.ignore();
        getline(cin, line);
        istringstream istream(line);
        int n;
        vector<int> l;
        while(istream >> n) {
           l.push_back(n); 
        }
        ostringstream output;
        output << "Test " << i << ":" << ":\n";
        for(const int &v : l) {
            output << v << " "; 
        }
        output << "\n";
        quicksort(l);
        for(const int &v : l) {
            output << v << " "; 
        }
        output << "\n";
        cout << output.str();
    }
}
