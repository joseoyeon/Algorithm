#include<bits/stdc++.h>
using namespace std;
#define INF 987978978
vector <pair<int, int>> v[501];
int Dist[501];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    int a,b,c;
    cin >> N >> M;
    while(M--){
        cin >> a>> b>> c;
        v[a].push_back(make_pair(b,c));
    }
    for(int i=1; i<=V; i++) {Dist[i] = INF;}

    priority_queue<pair<int, int>>PQ; 
    PQ.push(make_pair(0,1));
    Dist[1] = 0;

    while(PQ.empty() == 0){
        int cost = -PQ.top().first(); // cost
        int cur = PQ.top().second();
        PQ.pop();

        for(int i=0; i< v[cur].size(); i++){
            int next= v[cur][i].first;
            int ncost = v[cur][i].second;

            if(Dist[next] > cost + ncost ){
                Dist[next] = cost + ncost;
                PQ.push(make_pair(-Dist[next], next));
            }
        }
    }
    for(int i=1; i<=v; i++){
        if(Dist[i] == INF) cout << "INF" << endl;
        else cout << Dist[i] << endl;
    }
}