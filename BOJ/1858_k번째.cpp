#include<bits/stdc++.h>
#define MAX 2000000
using namespace std;

struct Data {
    int node, cost ;
    Data() {};
    Data(int node, int cost) : node(node), cost(cost) {};
};
vector <Data> v[MAX];
priority_queue <int> kmin[MAX]; // 코스들을 모두 들여보낸다. 
int n,m,k;

void dik(int start){
    priority_queue <pair<int, int>> pq; 
    pq.push(make_pair(start,0));
    kmin[start].push(0);

    while(!pq.empty()) {
        int now = pq.top().first;
        int ncost = -pq.top().second;
        pq.pop();

        for(int i=0; i<v[now].size(); i++) {
            int next = v[now][i].node;
            int nextcost = ncost + v[now][i].cost;

			if(kmin[next].size() < k || kmin[next].top() > nextcost){
                if(kmin[next].size() == k) kmin[next].pop();
                kmin[next].push(nextcost);
                pq.push(make_pair(next,-nextcost));
            }

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    int a,b,c;
    while(m--)  {
        cin >> a>>b >>c;
        v[a].push_back(Data(b,c));
    }

    dik(1); // 시작점

    for(int i=1; i<=n; i++){
        if(kmin[i].size() < k) {cout << -1 << endl;}
        else {cout << kmin[i].top() << endl;}
    }
    return 0;
}