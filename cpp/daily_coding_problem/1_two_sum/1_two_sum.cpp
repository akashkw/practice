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
