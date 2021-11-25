n = int(input())
dp = [0] * n

for i in range(0,n) :
    if i < 4 and i !=2 : 
        dp[i] = -1 
        continue
    if dp[i-3] == -1 and dp[i-5] == -1 : 
        dp[i] = -1
    elif dp[i-3] == -1:
        dp[i] = dp[i-5]+1
    elif dp[i-5] == -1 : 
        dp[i] = dp[i-3] +1
    else : 
        dp[i] = min(dp[i-3],dp[i-5]) +1
        
print(dp[n-1])
