#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;


vector <int> v[1001];
bool c[1001] = {false,};
bool b[1001] = {false,};

void dfs (int x) {
    if (c[x]) return ; 
    c[x] = true;
    printf("%d ", x);
    sort( v[x].begin(), v[x].end());
    for(int i =0 ; i<v[x].size(); i++){
        if (c[v[x][i]] == false){
            dfs(v[x][i]);

        }
    }
}

void bfs(int x){
    queue <int> q;
    q.push(x);  
    b[x] = true;
    while(!q.empty()){
        int current = q.front(); q.pop();
        printf("%d ",current);
        sort( v[current].begin(),  v[current].end());
        for(int i=0; i< v[current].size(); i++) {
            int tmp = v[current][i];
            if (!b[tmp]) {q.push(tmp); b[tmp] = true;}
        }
    }
}

int main(){
    int N,M,V;
    scanf("%d %d %d", &N, &M, &V);
    int a, b;
    for(int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    //dfs 
    dfs(V); 
    printf("\n");

    // bfs
    bfs(V);

    return 0;
}