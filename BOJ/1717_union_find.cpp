#include<iostream>
#include<algorithm>
using namespace std;
int parent[1000001];

int find(int x) {
	if (parent[x] == x)
		return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i < 1000001; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &c, &a, &b);
		if (c == 0) {
			merge(a, b);
		}
		else {
			if (find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}