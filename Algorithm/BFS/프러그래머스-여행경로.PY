from collections import defaultdict

def solution(tickets):
    answer = []
    graph = defaultdict(list)
    for t in tickets:
        graph[t[0]].append(t[1])

    for key in graph:
        # 이렇게 해야 알파벳 순으로 간다. 
        graph[key].sort()

    print(graph)
    def dfs(node, path):
        if len(path) == len(tickets) + 1 :
            return path
    
        for i, city in enumerate(graph[node]):
            graph[node].pop(i)
            print(node, path)
            print(graph)
            newPath = path[:]
            newPath.append(city)

            result = dfs(city,newPath)
            if result : return result

            graph[node].insert(i,city)


    answer = dfs('ICN',['ICN'])

    return answer

print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]))