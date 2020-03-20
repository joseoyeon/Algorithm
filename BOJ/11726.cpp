#include <stdio.h>
//다이나믹 프로그래밍

int d[1001];
int dp(int x){
    if(x == 1) return 1;
    if(x == 2) return 2;
    if(d[x] != 0) return d[x];
    return d[x] = (dp(x-1) + dp(x-2)) % 10007; 
}

int main() {
    int n; 
    scanf("%d", &n);
    int res = dp(n);
    printf("%d",res);
    return 0;
}