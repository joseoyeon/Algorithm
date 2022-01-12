#include<bits/stdc++.h>
#define MAX 987654321
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a,b,c;

    vector <pair<int, int>> v[502];
    long long dis[502];

    while(m--) {
        cin >> a >> b>> c;
        v[a].push_back(make_pair(b,c));
    }

    bool cycle = false;
    for(int i=1; i<=n; i++){dis[i] = MAX;}
    dis[1] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(auto &node : v[j]) {
                if(dis[j] != MAX && dis[node.first] > node.second + dis[j]) {
                    dis[node.first] = node.second + dis[j];
                    if(i==n) cycle = true;
                }
            }
        }
    }
    if (cycle) cout << "-1" << endl;
    else {
        for(int i=2; i<=n;i++){
            if(dis[i] == MAX) cout << "-1" << endl;
            else {cout << dis[i] << endl;}
        }
    }
    return 0;
}