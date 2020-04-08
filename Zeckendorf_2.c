                                                                                                                #include <stdio.h>
#include <stdlib.h>

long long int chi(long long int n) {
   int i, result =0;
   if (n ==1) {
       return 2;
   }

   for(i =0; i<=n; i++) {
       if(n == fibo(i)){
           result += fibo(i + 1);
           break;
       }
       else if (n < fibo(i)){
           result += fibo(i);
            n -= fibo(i-1);
            i =0;
       }
   }
   return result;
}

int fibo (int n) {
    int i, f1 =1, f2 =1, f3;
    if(n<2) {return 1;}
    for (i =2; i<=n; i++) {
        f3= f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}

int main() {
    long long int n; 
    char str[100]; 
    scanf("%s", str);
    n = atoi(str);
    //printf ("input : %d\n", n);
    long long int res = chi(n);
    printf ("res : %d",res);
    return 0;
}