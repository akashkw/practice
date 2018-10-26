from time import time
n, m, k = (map(int, input().split()))

def num_leq(n, m, x):
    count = 0
    for i in range(1, n+1):
        count += min(m, x//i)
    return count

lo = 0
hi = n * m

while lo + 1 < hi:
    mid = (lo + hi) // 2
    if num_leq(n, m, mid) >= k: hi = mid
    else: lo = mid
print(hi)
