def solution(prices):
    timer = [0] * len(prices)
    for cur in range(len(prices)-1) : 
        timer[cur] += 1 
        for j in range(cur+1,len(prices)-1) : 
            if prices[cur] <= prices[j] :
                timer[cur] += 1 
            else : 
                break
                
    return timer