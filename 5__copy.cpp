#include<iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정s

int getSmallIndex(int start, bool* visited, int* distance){
    int min = INF; 
    int index = 0;
    for(int i =1; i < N; i++) {
        if(distance[start][i]< min && visited[start][i]) {
            min = distance[i];
            index = i;
        }
    }
    return index; 
}

int main()
{
    int N,T;
    cin >> T;
    for (int x = 0; x < T; x++){
        cin >> N;
        
        int distance[100001][100001]; // 최소 비용을 저장함 
        bool visited[100001][100001];
        int u, v, cost; 
        int answer = INF ; 
        int count =0 ;
        for (int j = 1; j < N; j++){
            cin >> u >> v >> cost;
            distance[u][v] = cost; 
            distance[v][u] = cost; 
        }
    
        for (int start =1 ; start < N; start ++) {
            vistited[start][start] = true;
            for (int i =0 ; i < N-1; i++){
                int current = getSmallIndex(start, visited, distance);
                visited[start][current] = true; 
                visited[current][start] = true; 
                for(int j=start; j<N; j++) {
                    if(!visited[start][j]) {
                        if(distance[start][current] + distance[current][j] < distance[j]) {
                            distance[start][j] = distance[start][current] + distance[current][j];
                            distance[j][start] = distance[start][j] 
                        }
                    }
                }
            }
        }
        cout << "#" << x + 1 << " " << count << " " << answer << endl;
    }
return 0;
}