def solution(gems):
    answer = []
    gset = set(gems)
    
    start,end = 0,0
    gem_dict = dict()
    gem_dict[gems[start]] = 1
    
    while start < len(gems) and end < len(gems):
        if len(gem_dict) < len(gset): # 상품을 다 갖지 못했을 때
            end += 1
            if end >= len(gems):
                break
            if gems[end] not in gem_dict:
                gem_dict[gems[end]] = 1
            else:
                gem_dict[gems[end]] += 1
        else: # 모든 상품을 다 찾았을 때
            answer.append([start+1, end+1])
            # 한칸 앞으로 땡긴다. 
            start += 1
            gem_dict[gems[start-1]] -= 1
            if gem_dict[gems[start-1]] == 0:
                gem_dict.pop(gems[start-1])
    return min(answer, key=lambda x: (x[1]-x[0]))