num_shops = int(input())
shop_costs = sorted(map(int, input().split()))
num_days = int(input())

sol = list()

for d in range(num_days):
    today_money = int(input())
    lo = -1
    hi = len(shop_costs)
    while lo + 1 < hi:
        mid = int((lo + hi) / 2)
        if shop_costs[mid] <= today_money: lo = mid
        else: hi = mid
    sol += f"{lo + 1}"
    sol += "\n"
print("".join(sol[:-1]))
