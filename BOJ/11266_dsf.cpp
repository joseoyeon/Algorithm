#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int node, edge, s, e, cnt;
vector<int> v[10001], ans;
int visit[10001];
bool cut[10001] = { false, };

int dfs(int here, bool root) {
	visit[here] = ++cnt;
	int ret = visit[here];
	int child = 0;
	for (int i = 0; i < v[here].size(); i++) {
		int next = v[here][i];

		if (visit[next]) {
			ret = min(ret, visit[next]);
			continue;
		}
		child++;
		int prev = dfs(next, false);

		if (!root && prev >= visit[here]) 
			cut[here] = true;
		ret = min(ret, prev);
	}
    
	if (root && child > 1) {
		cut[here] = true;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	for (int i = 1; i <= node; i++)
		if (!visit[i])
			dfs(i, true);
	for (int i = 1; i <= node; i++) {
		if (cut[i])
			ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	system("pause");
	return 0;
}