#include<stdio.h>

int main(){
    long long d[101] = {0,1,1,1,2,2,};
    int n;
    for (int i=6; i<=100; i++) {
        d[i] = d[i-2] + d[i-3];
    }
    scanf("%d", &n);
    for (; n--;) {
        int p;
        scanf("%d",&p);
        printf("%lld\n", d[p]);
    }
    return 0;
}
//888855064897