
def solution(n, costs):
    # 코스트가 적은 비용 끼리 연결
    costs_sort = sorted(costs,key = lambda x : x[2])
    v = [i for i in range(n)]
    answer = 0

    for v1,v2, cost in costs_sort : 
        if v[v1] != v[v2] : # 둘이 연결되어 있지 않으면 
            # 둘중에서 최소 값으로 바꾸고 
            chage_index =  min(v[v1],v[v2])
            max_index = max(v[v1],v[v2])
            v[v1] = chage_index
            v[v2] = chage_index
            answer  +=cost
            # 정점 루트를 업데이트 한다. 
            for i in range(len(v)) : 
                if v[i] == max_index :
                    v[i] = chage_index

    return answer 

print(solution(5, [[0, 1, 5], [1, 2, 3], [2, 3, 3], [3, 1, 2], [3, 0, 4], [2, 4, 6], [4, 0, 7]]))