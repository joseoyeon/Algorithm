#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c;
// 정점1, 정점2, 비용 c
struct edge { int x, y, c; };
// 비용이 작은 순으로 정렬할 것 
bool cmp(edge u, edge v) { return u.c < v.c; }
vector<edge> g;
int par[1001];
 
// 유니온 파인드
int find(int x) {
    if (par[x] == x)return x;
    else return par[x] = find(par[x]);
}
 
int main() {
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        // 어차피 a=b면 사이클이므로 필요없음
        if (a != b) {
            g.push_back({ a,b,c });
        }
    }
    sort(g.begin(), g.end(), cmp);
    for (int i = 1; i <= n; i++)par[i] = i;

    int ans = 0;
    for (edge E : g) {
        if (find(E.x) != find(E.y)) {
            par[find(E.y)] = find(E.x);
            ans += E.c;
        }
    }
    cout << ans << '\n';
}
