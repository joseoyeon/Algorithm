#include<bits/stdc++.h>

using namespace std;


bool solve(int t);

int main()
{
	int u, v;
	int t = 1;
	while (true) 
		if (!solve(t++))break;	
	return 0;
}
bool solve(int t)
{
	bool ans = true;
	int u, v,root=-1;
	set<int> s;
	map<int, int> m;
	while (true) {
		cin >> u >> v;
		if (u == 0 && v == 0)break;
		else if (u < 0 && v < 0)return false;
		m[v]++;
		s.insert(u);
		s.insert(v);
	}
	for (auto u : s) {		
		if (m.find(u) == m.end()) {
			if (root == -1)
				root = u;
			else
				ans = false;
		}
		else if (m[u] > 1)
			ans = false;
	}
	if (!s.empty() && root == -1)ans = false;
	if (ans)cout << "Case " << t << " is a tree.\n";
	else cout << "Case " << t << " is not a tree.\n";
	return true;
}