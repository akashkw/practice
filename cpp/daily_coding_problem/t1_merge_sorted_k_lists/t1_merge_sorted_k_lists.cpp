#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

template <typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

vector<int> merge_sorted_lists(const vector<vector<int>> &lists) {
    min_pq<tuple<int, int, int>> pq;
    vector<int> sorted_list;
    for(int k = 0; k < lists.size(); k++) {
        pq.push({lists[k][0], k, 0});
    }
    while(!pq.empty()) {
        int value, list, index;
        tie(value, list, index) = pq.top();
        pq.pop();
        sorted_list.push_back(value);
        if(index + 1 < lists[list].size()) {
            pq.push({lists[list][index+1], list, index+1});
        }
    }
    return sorted_list;
}

int main() {
    vector<vector<int>> lists = {{10, 15, 30}, {12, 15, 20}, {17, 20, 32}};
    for(const int &i : merge_sorted_lists(lists)) cout << i << " ";
}
