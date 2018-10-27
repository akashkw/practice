from math import sqrt
def total_time(p, x, k):
    handshake = (p * (p-1))/2
    search_time = (p / x) * k
    return handshake + search_time

tests = int(input())
for t in range(tests):
    n, x, k = (map(int, input().split()))
    lo = 0
    hi = 2 + int(sqrt(2*n))
    while lo + 1 < hi:
        mid = hi - ((hi - lo) // 2)
        if total_time(mid, x, k) <= n: lo = mid
        else: hi = mid
    print(lo)
