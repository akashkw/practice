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
        mergesort(list);
        cout << "List after sort" << endl;
        for(const int &v : list) {
            cout << v << " ";
        }
        cout << endl << endl;
    }
}
