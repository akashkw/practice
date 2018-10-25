from math import floor
n, k = (map(int, input().split()))

def less_than_n(v, k):
    exp = 0
    total = 0
    while True:
        tmp = floor(v / (k**exp))
        if tmp <= 0: break
        total += tmp
        exp += 1
    return total < n
        
lo = 0
hi = n
while lo + 1 < hi:
    mid = int((lo + hi)/2)
    if less_than_n(mid, k): lo = mid
    else: hi = mid

print(hi)

