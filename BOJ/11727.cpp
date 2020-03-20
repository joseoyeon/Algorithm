#include<stdio.h>

int d[1001];

int dp(int n) {
    if(n == 1) return 1;
    if(n == 2) return 3;
    if(d[n] != 0) return d[n];
    return d[n] = (dp(n-1) + 2*dp(n-2)) % 10007;
}

int main() {
    int n ;
    scanf("%d",&n);
    int res = dp(n);
    printf("%d",res);
    return 0;
} 