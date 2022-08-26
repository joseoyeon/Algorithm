#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M,V;
vector <pair<int, int>> node; 

void dfs (int V){
    int visite[10001] = {false,};
    
    visite[V] = true;
    for(int next=0 ;next < node[V].size(); next++){
        if (visite[ node[V][next]] == false){
            visite[node[V][next]] = true;
            printf("%d ",node[V][next]);
            dfs(next);
        }
    }
}

void bfs(int V){
    int visite[10001] = {false, };

    queue <int> q;
    q.push(V); 
    visite[V] = true;
    while(!q.empty()){
        int start = q.top(); q.pop();
        printf("%d ", start);
        for(int i=0 ;i < node[start].size(); i++){
            if (visite[node[start][i]] == false){
                q.push(node[start][i]);
                visite[node[start][i]] = true;
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &V);
    for(int m =0; m < M; m++){
        int a, b;
        scanf("%d %d", &a,&b);
        node.push_back(make_pair(a,b));
        node.push_back(make_pair(b,a));
    }

    dfs(V);
    bfs(V);
    return 0;
}