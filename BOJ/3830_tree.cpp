#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
int parent[MAX];
int saveweight[MAX];

int getparent(int a) {
	if(parent[x] == x) return x;
	return parent[x] = getparent(parent[x]); 
}

int merge(int a, int b){
	int pa = getparent(a);
	int pb = getparent(b);
	if(pa > pb) {parent[a] = pb;}
	else { parent[b] = pa; }
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	char c;
	int a,b,w;

	for(int i=0; i<n;i++){
		parent[i] = i;
	}

	while(m--) {
		cin >> c >> a >>b >> w;
		if(c == '?') {
			if(getparent(a) == getparent(b)){
				
			}else {
				cout << "UNKNOWN" << endl;
			}
		}
		if(c == '!'){
			merage(a,b);

		}
	}
	return 0;
}