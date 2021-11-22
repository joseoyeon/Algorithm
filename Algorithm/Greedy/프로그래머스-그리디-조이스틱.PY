def solution(name):
    answer = 0
    switch_pos = []
    # 알파벳 차이 계산하는 것
    for i, x in enumerate(name) : 
        if x != 'A' : 
            answer += min(abs(ord(x)-ord('A')), abs(ord('Z') - ord(x)+ 1))  
            switch_pos.append(i)
    
    # 그리디하게 최소 이동 위치 찾기 
    current = 0 
    for _ in range(len(switch_pos)):
        move_list = [min(abs(x-current), len(name)-abs(x-current)) for x in switch_pos]
        answer += min(move_list)
        current = switch_pos.pop(move_list.index(min(move_list)))
    return answer