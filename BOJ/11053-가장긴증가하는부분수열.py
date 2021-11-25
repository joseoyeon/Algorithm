n = int(input())
list_ = list(map(int, input().split()))

dp = [1] * n 

for i in range(1,n) :
    for j in range(0,i) :    
        if list_[i] > list_[j] : 
            dp[i] = max(dp[i], dp[j] +1 )  

print(max(dp))
