#include<bits/stdc++.h>
#include<queue>
using namespace std; 
vector<int> line[32000]; 
int indegree[32000];
int n,m; 

int result[32000]; 
void topologySort() { 
    queue<int> q; 
    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    for(int i=1; i<=n; i++){
        if(q.empty()) {return;}
        int x = q.front();
        result[i]= x;
        q.pop();
        for(int j=0; j< line[x].size(); j++) {
            int y = line[x][j];
            if(--indegree[y] == 0) {
                q.push(y);
            }
        }
    } 

}
int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m; 
    int a,b; 

    while(m--){
        cin >> a >>b ; 
        line[a].push_back(b); 
        indegree[b] ++; 
    }
    topologySort(); 
    for(int i=1; i<=n; i++) {
        cout << result[i]<< " " ;
    }
}