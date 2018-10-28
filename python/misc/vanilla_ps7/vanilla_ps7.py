tests = int(input())
for t in range(tests):
    target = int(input())
    dp = [0 for x in range(target+1)]
    for i, m in enumerate(dp):
        one = 0
        five = 0
        ten = 0
        twenty_five = 0
        if i >= 1:
            one = dp[i-1]
        if i >= 5:
            five = dp[i-5]
        if i >= 10:
            ten = dp[i-10]
        if i >= 25:
            twenty = dp[i-25]
        if i == 0:
            one = 1
        dp[i] = one + five + ten + twenty_five
    print(dp[target])
