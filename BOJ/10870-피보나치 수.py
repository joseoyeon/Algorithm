n = int(input())

dp = [0] * 20
dp[0] = 1
dp[1] = 1

for i in range(n) : 
    if dp[i] == 0 : 
        dp[i] = dp[i-1] + dp[i-2]

print(dp[n-1])