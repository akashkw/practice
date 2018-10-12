#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int len;
    cin >> len;
    vector<int> v;
    while(len--) {
        int i;
        cin >> i;
        v.push_back(i);
    }
    sort(begin(v), end(v));
    for (const int &i : v) {
        printf("%d ", i);
    }
    cout << endl;
}
