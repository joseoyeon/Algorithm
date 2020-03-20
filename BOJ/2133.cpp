#include <stdio.h>

int d[1001];

int dp(int x) {
    int result;
    if(x == 0) return 1; // 곱하기 해야함
    if(x == 1) return 0;
    if(x == 2) return 3;
    if(d[x] != 0) return d[x];
    result = 3*dp(x-2);
    for(int i=3; i <= x; i++ ){
         if(x%2 == 0) result += 2 * dp(x-i);
    }
    return d[x] = result;
}

int main() {
    int x;
    scanf("%d",&x);
    printf("%d", dp(x));
    return 0;
}