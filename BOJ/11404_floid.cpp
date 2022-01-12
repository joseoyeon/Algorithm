#include<bits/stdc++.h>
#define MAX 987654321
using namespace std;
int n, m;
int a,b,c;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int node[101][101];

    for(int i=1;i<=n;i++){
        for(int j=1; j<=n;j++){
            node[i][j]=MAX;
        }
    }
    for(int i=1; i<=n;i++){
        node[i][i] = 0;
    }
    while(m--) {
        cin >> a >> b >> c;
        if(node[a][b] > c){node[a][b] = c;}
    }

    // 플로이드 
    for(int j= 1; j<=n; j++) {
        for(int i = 1; i<=n; i++) {
            for(int k=1; k<=n; k++){
                if(node[i][k] > node[i][j] + node[j][k]){
                    node[i][k] = node[i][j] + node[j][k];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j || node[i][j] == MAX){
                node[i][j] = 0;
            }
            cout << node[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}