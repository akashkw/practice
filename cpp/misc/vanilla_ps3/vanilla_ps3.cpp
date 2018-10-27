#include <iostream>
#include <cmath>
using namespace std;

long long total_time(uint64_t p, long long x, long long k) {
    long long handshakes = (p * (p-1)) / 2;
    long long search_time = (p/x) * k;
    return handshakes + search_time;
}

int main() {
    int tests;
    cin >> tests;
    while(tests--) {
        long long n, x, k;
        cin >> n >> x >> k;
        uint64_t lo(0), hi(2+(uint64_t)sqrt(2*n));
        while(lo + 1 < hi) {
            uint64_t mid = (lo + hi) >> 1;
            if(total_time(mid, x, k) <= n) lo = mid;
            else hi = mid;
        }
        cout << lo << "\n";
    }
}
