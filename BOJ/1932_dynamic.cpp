#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int map[n][n+1];
    int result[n][n];

    for(int i=0; i<n; i++) {
        for(int j=1; j<i+2; j++){
            cin >> map[i][j];
        }
        map[i][0] = 0;
        map[i][i+2] = 0;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<i+2; j++){
            map[i][j] += max(map[i-1][j-1], map[i-1][j]);
        }
    }
    int answer = 0;    
    for(int j =1; j<n+1; j++){
        answer = max(answer, map[n-1][j]);
    }
    cout <<answer <<endl; 

    return 0;
}