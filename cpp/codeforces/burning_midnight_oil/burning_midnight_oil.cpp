#include <iostream>
#include <cmath>
using namespace std;

long long n, k;

bool less_than_n(long long v, long long k) {
    long long exp = 0;
    long long sum = 0;
    while(true) {
        long long tmp = floor(v / (pow(k, exp)));
        if(tmp <= 0) break;
        sum += tmp;
        exp++;
    }
    return sum < n;
}

int main() {
    cin >> n >> k;

    long long lo(0), hi(n);
    while(lo + 1 < hi) {
        long long mid = (long long)((lo + hi) / 2);
        if(less_than_n(mid, k)) lo = mid;
        else hi = mid;
    }
    cout << hi;
}
