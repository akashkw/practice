#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll num_leq(ll n, ll m, ll x) {
    ll less_count = 0;
    for(int i = 1; i <= n; i++) {
        less_count += min(m, x/i);
    }
    return less_count;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll lo(0), hi(n*m+1);
    while(lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if(num_leq(n, m, mid) >= k) hi = mid;
        else lo = mid;
    }
    cout << hi;
}
