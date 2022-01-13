#include<bits/stdc++.h>
using namespace std;
int n,m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int map[1001][1001];
    string s;

    for(int i=1; i<=n;i++){
        cin >> s;
        for(int j=0; j<m; j++){
            map[i][j+1] = s[j] - 48;
        }
    }
    
    int answer =0 ;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=m; j++){
            if(map[i][j] != 0) {
                map[i][j] = min(min(map[i-1][j],map[i-1][j-1]), map[i][j-1]) +1;
                answer = max(answer,map[i][j]);
            }
        }
    }


    cout << answer*answer << endl;
    return 0;
}