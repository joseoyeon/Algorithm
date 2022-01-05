#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#define SIZE 52 
#define MAX(X,Y) X > Y ? X:Y
using namespace std; 

// 움직이는 거니까 
int map[SIZE][SIZE], dp[SIZE][SIZE], visited[SIZE][SIZE];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int N,M;

int dfs(int x, int y) {
    if (x<0 || y< 0|| x>=M || y>=N || !map[y][x]) return 0;
    if(visited[y][x]) {cout << -1 << endl; exit(0);}
    if (dp[y][x]) return dp[y][x];
    visited[y][x] =1;
    for(int i=0; i<4; i++) 
        dp[y][x] = MAX(dp[y][x], dfs(x+map[y][x] * dx[i], y+map[y][x] * dy[i]) +1);
    visited[y][x] =0;
    return dp[y][x];
    
}
int main(){
    cin >> N >> M ;
    for (int i =0; i<N; i++) {
        for (int j =0 ; j<M; j++){
            char c; 
            cin >> c;
            if(c <= '9') map[i][j] = c - '0';
        }
    }
     cout << dfs(0,0) << endl;
    return 0;
}