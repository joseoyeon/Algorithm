#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;


int main()
{
    int N = 0; // 5-1000
    int M =0 ; // 4-3000
    int T = 0;
    int A_start =0; 
    int B_start =0;
    
    cin >> T ;
    for (int x = 0; x < T; x++){
    	int check [3001] = {0,};   
        vector<int> graph[3001];

        cin >> N >> M; // 거점의 수와 연결된 간선의 수 
        cin >> A_start >> B_start ; // A,B의 출발점 받기 
        // 입력
        for (int j = 0; j < M; j++){
            int u,v ; 
            cin >> u >> v ;
		    graph[u].push_back(v);
		    graph[v].push_back(u);
        }
        queue<int> A_que;
        queue<int> B_que;

     // 첫번째 시작점 넣어 주기 
     A_que.push(A_start);
     check[A_start] = 1;
     B_que.push(B_start);
     check[B_start] = 2;

    ////
    for(int k = 1 ; k < M+1; k++){
        for(auto loop : graph[k]) {
            cout<<"Range : "<< k << " - " << loop << endl;
        }
    }
    ///

    ///que cout 
    while (!A_que.empty() && !B_que.empty()){
        int A ; 
        int B ; 
        if (!A_que.empty()) {
            A = A_que.front(); // 첫번째 가져오기 
            cout <<"A front : " << A << endl; 
        }   
        
        if (!B_que.empty()) {
            B = B_que.front(); // 첫번째 가져오기 
        cout <<"B front : " << B << endl; 
        }

        if (!A_que.empty()) {    
            A_que.pop();
            for(int i =0; i< graph[A].size(); i++) {
                // 연결된 정점들을 돌면서 
                cout << "A graph : " << graph[A][i] <<  endl;
                if(check[graph[A][i]] ==0) {// 아직 점령하지 않은 지역이지만, 
                    for(int t =0; t< graph[B].size(); t++) { 
                        // B 에도 있는 지역이면 
                        if (graph[A][i] == graph[B][t]) {
                            check[graph[A][i]] = 3; // 대치거점이다.
                            break;        
                        }
                    }
                }
                //만약 대치 지점이 아니라면 
                if(check[graph[A][i]] ==0) {
                    //큐에 넣어준다. 
                    cout << "push " << graph[A][i] << endl;
                    A_que.push(graph[A][i]);
                    check[graph[A][i]] = 1;
                 }
            }
        }
        cout << endl; 
        if (!B_que.empty()) {
            B_que.pop();    
            for(int i =0; i< graph[B].size(); i++) {
                cout << "B graph : " << graph[B][i] <<  endl;
                if(check[graph[B][i]] ==0) {
                    // 아직 점령하지 않은 지역이지만, 
                    for(int t =0; t< graph[A].size(); t++) { 
                        // A 에도 있는 지역이면 
                        if (graph[A][t] == graph[B][i]) {
                            check[graph[B][i]] = 3; // 대치거점이다.
                            break;        
                        }
                    }
                }
                //만약 대치 지점이 아니라면 
                if(check[graph[B][i]] ==0) {
                    //큐에 넣어준다. 
                    cout << "push " << graph[B][i] << endl;
                    B_que.push(graph[B][i]);
                    check[graph[B][i]] = 2;
                }
            }
        }
        
        for (int p =1 ; p<N+1; p++) {
            cout << check[p] << ' ' ;
        }

    cout << endl; 
    }

    
    int country =0;
    int answer_space = 0;
    int A = 0;
    int B = 0;
    // 그 숫자+A의 거점 국가 수 > B의 거점 국가 수 가 안된다면 -1 을 반환하기 
    for (int i=1; i<N+1;i++){
        if (check[i] == 1 ) {
            A += 1;
        }else if (check[i] == 2 ) {
            B += 1;
        }else if (check[i] == 3){
            answer_space += 1;
            country += 1;
        }else {
            country += 1;
        }
    }
    if (A + country <= B) {country = -1;}
    if (A > B ) { country = 0;}

        cout << "#" << x + 1 << " " << answer_space << " " << country << endl;
    }
    
return 0;
}