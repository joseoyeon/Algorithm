n = int(input())
list_ = list(map(int, input().split()))

dp1 = [1] * n 
dp2 = [1] * n 

# 여긴 가장 긴 부분 수열 
for i in range(1,n) :
    for j in range(0,i) :    
        if list_[i] > list_[j] : 
            dp1[i] = max(dp1[i], dp1[j] +1 )  
 
for i in range(n-1,-1,-1) :
    for j in range(n-1,i,-1) :    
        if list_[i] > list_[j] : 
            dp2[i] = max(dp2[i], dp2[j] +1)  

print(max(list(map(lambda x,y: x+y, dp1,dp2)))-1)
