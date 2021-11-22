import re 

PRIME = [1] * 1000000
PRIME[1] = 0

def prime(n):
    if PRIME[n] == 0 : 
        return PRIME[n]
    for i in range(2, int(n**0.5)+2):
        if PRIME[i+1] == 1:
            for j in range(i+1, n, i) : 
                PRIME[j+1] = 0
    return PRIME[n]

def solution(n, k):
    # 진법 변환
    string_ = ""
    ans = 0
    while n >= 1:
        n,r = divmod(n,k) 
        string_ += str(r)
    answer =list(filter(None,re.split('0',string_)))
    
    print(answer)
    for number in answer :
        print(number,prime(int(number))) 
        ans += prime(int(number))

    return ans

print(solution(	11, 10))