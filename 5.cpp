#include<iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정s

int main()
{
    int N,T;
    cin >> T;
    for (int x = 0; x < T; x++){
        cin >> N;
        
        vector<pair<int, int>> graph[100001];
        int distance[100001]; // 최소 비용을 저장함
        bool visited[100001]; // 최단 거리 테이블 만들기 
        fill_n(distance, 100001, INF); // 연결되지 않았으면 무한이다. 
        int u, v, cost; 
        int answer = INF ; 
        int count =0 ;
        for (int j = 1; j < N; j++){
            cin >> u >> v >> cost;
            graph[u].push_back(make_pair(v, cost));
            graph[v].push_back(make_pair(u, cost));
        }

        // 다익스트라 알고리즘 사용하기 시작 번호는 1  
        for (int start = 1; start < N+1; start ++ ) { 
            distance[start] =0; 
            priority_queue<pair<int, int>> pq; // 힙
            
            pq.push(make_pair(start,0)); // 첫번째 정점 넣기 

            while(!pq.empty()) {
                int current = pq.top().first; // 연결된 정점
                //짧은 것이 더 먼저 오도록 - 붙여서 정렬한다. 
                int dis = -pq.top().second; // 비용 
                pq.pop();

                //최단 거리가 아니면 넘어 감
                if(distance[current] < dis) continue;
                for(int i =0; i<graph[current].size(); i++) {
                    int next= graph[current][i].first; // 연결된 정점
                    int nextDistance = dis + graph[current][i].second; // 거리 

                    if(nextDistance < distance[next]) {
                        distance[next] = nextDistance; 
                        pq.push(make_pair(next, -nextDistance));
                    }
                }
            }
            int tmp_answer =0 ; 
            cout << start << " : " ; 
            for (int i = 1; i< N+1; i++) {cout << distance[i] << " "; tmp_answer += distance[i];}
            if (tmp_answer < answer) {count = 1; answer = tmp_answer;}
            else if (tmp_answer == answer) {count += 1; }
            cout << endl;
            cout << tmp_answer << endl;  
            cout << "#" << x + 1 << " " << answer << " " << count << endl;
            fill_n(distance, 100001, INF); // 그 다음 정점 연결 확인을 위해 초기화 한다. 
        }
        
        cout << "#" << x + 1 << " " << count << " " << answer << endl;
    }
return 0;
}