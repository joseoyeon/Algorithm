from collections import deque
def solution(progresses, speeds):
    answer = [] 
    deq = deque()
    time, work = 0, 0
    for p,s in zip(progresses, speeds) :
        deq.append((p,s))
        
    time = (100 - progresses[0])//speeds[0] + (1 if (100-progresses[0])%speeds[0] != 0 else 0) 

    while deq :
        p,s = deq.popleft()
        if p + time*s >= 100 :
            work +=1    
        else : 
            time = (100 - p)//s + (1 if (100-p)%s != 0 else 0) 
            answer.append(work)
            work = 1
        if not deq : 
            answer.append(work)
        
    return answer

print(solution([20, 99, 93, 30, 55, 10], [5, 10, 1, 1, 30, 5]))