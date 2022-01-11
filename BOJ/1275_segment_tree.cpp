#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, Q;
ll tree[4000001];
ll a[1000001];
 
void update(int node, int st, int ed, int idx, int val) {
    if (st == ed) {
        tree[node] = val;
        return;
    }
    int mid = (st + ed) >> 1;
    if (idx <= mid) update(2 * node, st, mid, idx, val);
    else update(2 * node + 1, mid + 1, ed, idx, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
 
ll query(int node, int st, int ed, int qst, int qed) {
    if (qst > ed || qed < st) return 0;
    if (qst <= st && ed <= qed) return tree[node];
    int mid = (st + ed) >> 1;
    ll q1 = query(2 * node, st, mid, qst, qed);
    ll q2 = query(2 * node + 1, mid + 1, ed, qst, qed);
    return q1 + q2;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        update(1, 1, n, i, num);
    }
    while (Q--) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        cout << query(1, 1, n, x, y) << '\n';
        update(1, 1, n, a, b);
    }
}
