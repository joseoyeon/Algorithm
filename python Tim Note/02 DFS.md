### python 

```python

def dfs(graph,v, visited) : 
    # 현재 노드를 방문 처리
    visited[v] = True
    print(v, end="")
    for i in graph[v] : 
        if not visited[i] :
            dfs(graph, i, visited)


graph = [
    [],
    [2,3,8], 
    [1,7],
    [1,4,5],
    [3,5],
    [7],
    [2,6,8],
    [1,7]
]

# 각 노드가 방문된 정보를 표현 
visited = [False] * 9

dfs(graph,1, visited)
```

### C++

```C
# include <bits/stdc++.h>

using namespace std;

bool visited[9] ; 
vector<int> graph[9];

void dfs(int x) {
    visited[x] = true;
    cout << x << ' ' ;
    for (int i =0; i<graph[x].size(); i++) {
        int y = graph[x][i] ;
        if (!visited[y]) dfs(y);
    }
}

int main(void) {
    dfs(1);
    return 0;
}
```

### JAVA

```java
import java.util.*;

public clss Main{
    public static boolean[] visited = new boolean[9];
    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();

    public static void dfs(int x) {
        visited[x] = true; 
        System.out.print(x + "") ;

        for(int i =0; i < graph.get(x).size(); i++){
            int y = graph.get(x).get(i);
            if(!visited[y]) dfs(y);
        }
    }

    public static void main(String[] args){
        dfs(1);
    }
}
```

