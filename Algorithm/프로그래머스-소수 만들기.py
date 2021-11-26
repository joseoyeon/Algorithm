from itertools import combinations 
import math

prime = [True] * 3001
prime[1] = False

for i in range(2,math.ceil(math.sqrt(3001))) : 
    if prime[i] :
        for j in range(i,int(3001/i)) : 
            prime[i*j] = False
            
def solution(nums):
    answer = [i for i in combinations(nums, 3) if prime[sum(i)] == True]
    return len(answer)