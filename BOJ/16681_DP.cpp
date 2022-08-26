#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, D, E, a, b, cost;
typedef pair<ll, ll> pi;
vector<pi> g[100001];
ll h[100001], dist1[100001], dist2[100001];
 
//시작점 1인 다익
void dijk() {
    priority_queue<pi>pq;
    for (int i = 0; i < n; i++) dist1[i] = 1e18;
    dist1[1] = 0; pq.push({ 0,1 });
    while (!pq.empty()) {
        ll x = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();
        if (dist1[x] != d) continue; 
        for (pi nxt : g[x]) {
            ll nx = nxt.first;
            ll nd = nxt.second + d;
            if (h[nx] <= h[x]) continue;
            cout << x << " " << h[x] << " : " << nx << " "<< h[nx]<< " "  <<nd <<" "<< endl;
            if (dist1[nx] > nd) {
                dist1[nx] = nd;
                pq.push({ -dist1[nx], nx });
            }
        }
    }
}
 
//시작점 n인 다익
void dijk2() {
    priority_queue<pi>pq;
    for (int i = 0; i < n; i++) dist2[i] = 1e18;
    dist2[n] = 0; pq.push({ 0,n });
    while (!pq.empty()) {
        ll x = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();
        if (dist2[x] != d) continue;
        for (pi nxt : g[x]) {
            ll nx = nxt.first;
            ll nd = nxt.second + d;
            if (h[nx] <= h[x]) continue;
            cout << x << " " << h[x] << " : " << nx << " "<< h[nx]<< " "  <<nd <<" "<< endl;
            if (dist2[nx] > nd) {
                dist2[nx] = nd;
                pq.push({ -dist2[nx], nx });
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> D >> E;
    for (int i = 1; i <= n; i++) cin >> h[i];
    while (m--) {
        cin >> a >> b >> cost;
        g[a].push_back({ b, cost });
        g[b].push_back({ a, cost });
    }
    dijk();
    cout << "Dafd" << endl;
    dijk2();
    ll ans = -1e18;
    for (int k = 2; k <= n - 1; k++) {
        if (dist1[k] == 1e18 || dist2[k] == 1e18) continue;
        //가치의 최대 갱신
        ans = max(ans, E * h[k] - (dist1[k] + dist2[k]) * D);
    }
    if (ans == -1e18) cout << "Impossible" << '\n';
    else cout << ans << '\n';
}
