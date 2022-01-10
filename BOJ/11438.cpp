#include<bits/stdc++.h>
using namespace std;
vector<int> node[100000];
int connect[100000];

int find_lea() {
    // 일단 공통 조상 찾을 때는 항상 
    int dot[1000000][1000000];
    queue<int> dot; 
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m; 
    cin >> n;

    while(n--){
        int a,b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    find_lea(); 

    cin >> m;
    while(m--){
        int p,q;
        cin >> p >> q; 
        int root ; 
        if()
        if(root == 1) {break;} // 끝까지 순환 완료 
    }

    return 0;
}