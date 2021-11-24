from collections import deque

def solution(priorities, location):
    que = deque()
    answer = 0 
    for a,b in zip(priorities, [i for i in range(len(priorities))]) :
        que.append((a,b))

    while True : 
        max_v = max(priorities)
        print(que)
        a,b = que.popleft()
        if max_v > a : 
            que.append((a,b))
        else :    
            if b == location : 
                return answer
            else : 
                property
                answer += 1  
    return answer
print(solution([1, 1, 9, 1, 1, 1],	0))