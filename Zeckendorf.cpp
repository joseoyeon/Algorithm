#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Uint;

unsigned int chi(unsigned int N) {
    unsigned int fibo1 = 1; 
    unsigned int fibo2 = 1;
    unsigned int tmp1 =0;

    unsigned int res=0;
    while (1){ 
        tmp1 = fibo1;
        fibo1 = (fibo1 + fibo2);
        fibo2 = tmp1;

        if(N == 0) break;
        if(N == 1) {res += 1; break;}
        if(N == 2) {res += 1; break;}
        if(N == 3) {res += 2; break;}
    
        if (fibo1 < N && N <= (fibo1 + fibo2)){
            if((fibo1 + fibo2) == N) {return res= fibo1; } 
            else {
                (res = (fibo2 + chi(N-fibo1)));
                return res; 
            } 
        }
    }
}

  int main() {
    unsigned int n; 
    char str[100]; 
    scanf("%s", str);
    n = atoi(str);
    unsigned int res = chi(n);
    printf("%d",res);
    return 0;
}
