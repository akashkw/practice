tests = int(input())
for t in range(tests):
    num_jewels, capacity = (map(int, input().split()))
    jewels = [(0,0)]
    for n in range(num_jewels):
        jewels.append(tuple(map(int, input().split())))
    dp = [[0 for w in range(capacity+1)] for j in jewels]
    for i, tup in enumerate(jewels):
        if i == 0: continue
        value, weight = tup
        for w in range(capacity+1):
            max_value = dp[i][w]
            for tmp_tup in jewels[:i+1]:
                tmp_val, tmp_weight = tmp_tup
                if tmp_weight > w: continue
                max_value = max(max_value, dp[i-1][w], dp[i-1][w-tmp_weight] + tmp_val)
            dp[i][w] = max_value
print(dp[-1][-1])
