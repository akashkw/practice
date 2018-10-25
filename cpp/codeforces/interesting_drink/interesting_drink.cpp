#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num_shops, num_days;
    cin >> num_shops;
    vector<int> shops;
    for(int i = 0; i < num_shops; i++) {
        int x;
        cin >> x;
        shops.push_back(x);
    }
    sort(begin(shops), end(shops));
    cin >> num_days;
    for(int i = 0; i < num_days; i++) {
        int today_money;
        cin >> today_money;
        int lo = -1;
        int hi = shops.size();
        while(lo + 1 < hi) {
            int mid = (int) ((lo + hi) / 2);
            if(shops[mid] <= today_money) lo = mid;
            else hi = mid;
        }
        cout << lo + 1 << endl;
    }

}
