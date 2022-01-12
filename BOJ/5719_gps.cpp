#include<bits/stdc++.h>
#define INF 987654321
using namespace std;

struct Data {
    int node, weight;
    Data(int node, int weight) : node(node), weight(weight){};
    bool operator <(const Data d) const {
        return weight > d.weight;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m;
    int u,v,p;
    int s,d;
    vector <Data> vec[502];
    bool visite[502];
    int dis[502];

    cin >> n >> m;

    while(n || m){
        cin >> s >> d; 
       
       // 초기화 
       for(int i =0; i<=n; i++){
           vec[i].clear();
            dis[i] = INF;
            visite[i] = false;
       }
        while(m--){
            cin >> u >> v >> p;
            vec[u].push_back(Data(v,p));
        }

    /// 다익스트라 시작 
        dis[s] = 0;
        priority_queue<Data> pq;
        priority_queue<int> q;
        pq.push(Data(s,0));
        while(true) {
            if(pq.empty()) break;
            Data cur = pq.top();
            pq.pop();
            if(visite[cur.node]) continue;
            visite[cur.node] = true;
            for(auto &next : vec[cur.node]) {
                if(next.node == d) {q.push(-(dis[cur.node] + next.weight));}
                 if(dis[next.node] > dis[cur.node] + next.weight){
                    dis[next.node] = dis[cur.node] + next.weight;
                    pq.push(Data(next.node, dis[next.node]));
                }
            }
        }

        int tmp = -1; 
        while(!q.empty()) {
            cout<< -q.top() << endl;
            q.pop();
        }
        cin >> n >> m;
    }
    return 0;
}