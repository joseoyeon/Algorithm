#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

class road {
    public :
        int a,b,c;
        road(int a, int b, int c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
    bool operator<(road &road) {return this->c < road.c;}
;

vector <road> v;

int find_parent(int* root, int a) {
    if(root[a] == a) { return a;}
    return root[a] = find_parent(root[a]);
}

int merge(int* root, int a, int b){
    int pa = find_parent(root, a);
    int pb = find_parent(root, b);
    if(pa > pb) {root[a] = pb;}
    else{root[b] = pa;}
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    scanf("%d",&n);
    int root[n+1];
    int sol[n+1][n+1];
    
    while(n--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v.push_back(road(a,b,c));
    }

    sort(v.begin(), v.end());
    for(int i=1; i<n+1; i++) {root[i] = i;}

    int sum =0;
    for(auto node : v) {
        if (find_parent(node.a -1) != find_parent(node.b -1)) { 
            sol[node.a][node.b] = node.c;
            sol[node.b][node.a] = node.c;
            merge(root, node.a -1,node.b -1);
        }
    }

    int k;
    scanf("%d",&k);
    while(k--){
        int d,e;
        printf("%d \n", &sol[d][e]);
    }
    return 0;

}