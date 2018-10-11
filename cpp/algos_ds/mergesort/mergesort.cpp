#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<int> merge(vector<int> &list1, vector<int> &list2) {
    vector<int> sorted; 
    auto list1_ptr = begin(list1);
    auto list2_ptr = begin(list2);
    while (list1_ptr != end(list1) || list2_ptr != end(list2)) {
        if (list1_ptr == end(list1)) {
            sorted.push_back(*list2_ptr);
            list2_ptr++;
            continue;
        }
        if(list2_ptr == end(list2)){
            sorted.push_back(*list1_ptr);
            list1_ptr++;
            continue;
        }
        if(*list2_ptr < *list1_ptr) {
            sorted.push_back(*list2_ptr);
            list2_ptr++;
        }
        else {
            sorted.push_back(*list1_ptr);
            list1_ptr++;
        }
    }
    return sorted;
}

vector<int> mergesort_helper(vector<int> list) {
    if(list.size() <= 1) {
        return list;
    }
    vector<int> left = vector<int>(begin(list), begin(list) + (list.size() / 2));
    vector<int> right = vector<int>(begin(list) + (list.size() / 2), end(list));
    left = mergesort_helper(left);
    right = mergesort_helper(right);
    return merge(left, right);
}

void mergesort(vector<int> &list) {
    list = mergesort_helper(list);
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
        mergesort(l);
        for(const int &v : l) {
            output << v << " "; 
        }
        output << "\n";
        cout << output.str();
    }
}
