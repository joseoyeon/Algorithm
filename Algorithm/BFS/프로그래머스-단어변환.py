from collections import deque 

def hashdistance(w1, w2) :
    difference =0 
    for i in range(len(w1)) :
        if w2[i] != w1[i] :
            difference += 1 
    return difference 

def solution(begin, target, words): 
    # 타겟이 없을때 
    if not(target in words):
        return 0

    visited = set()
    queue = deque()
    queue.append((0,begin))

    # 깊이와 word를 저장한 queue를 만드는 것이 핵심이다. 
    while queue:
        length, word = queue.popleft()
        visited.add(word)
        if word == target:
            return length
        else :
            for i in range(len(words)) :  
                if words[i] not in visited :
                    if hashdistance(words[i],word) ==  1:
                        queue.append((length + 1,words[i]))
                        visited.add(words[i])
        print(queue)
        print(visited)
        print(length, word, target)
        
    return 0

print(solution("hit", "hhh", ["hhh","hht"] ), 4)