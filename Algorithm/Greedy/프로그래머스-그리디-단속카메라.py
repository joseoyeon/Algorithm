def solution(routes):
    # 정렬을 하지 않으면 온 차례로 구간을 설정할 수 없다. 
    # 먼저 온 차가 출차된 마지막 순
    routes = sorted(routes)
    term = []
    for i in routes:
        
        # 아무런 구간에도 설치하지 않았다면 추가한다. 
        if not term:
            term += [i]
            continue
        
        # 현재 가진 구간에 속해 있지 않다면 그 구간에 추가한다. 
        for j in term:
            if j[0] <= i[0] <= j[1] or j[0] <= i[1] <= j[1]:
                if j[0] < i[0]: j[0] = i[0]
                if i[1] < j[1]: j[1] = i[1]
                break
        else: 
            term += [i]

    return len(term)