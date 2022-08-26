#include<iostream>
#include<bits/stdc++.h>
#define MAX 16
#define INF 987654321
using namespace std;

int N;
int map[MAX][MAX];
int dp[MAX][(1<<MAX)];
int maxBit=0;

int dfs(int n, int bit){
    if(bit == maxBit){

    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin >> N; 

    for(int i =0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    maxBit = (1<<N) - 1;

    for(int i=0; i<N; i++) {
        for(int j=0; j<= maxBit; j++){
            dp[i][j] = INF;
        }
    }
    
    cout << dfs(0,1) << endl;

    return 0;

}