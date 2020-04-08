# include<stdio.h>                                                                                                           #include <stdio.h>
# include<stdlib.h>

long long int F[50]; 

long long int fibo (int n) {
    int i, f1 =1, f2 =1, f3;
    if(n<2) {return 1;}
    if (F[n] != 0 ) return F[n];

    for (i =2; i<=n; i++) {
        f3= f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return F[n] = f3;
}

long long int chi(int n) {
   int i;
   int result =0;
   int p = n;

   for(int i=3; i<p; i++) {
        if (n==0) {break;}
        if (n==3) {result += 2; break;}
        if (n==1) {result += 1; break;}
        if (n==2) {result += 1; break;}

        if (fibo(i-1) < n && n <= fibo(i)){
            if(n == fibo(i)){
                result += fibo(i - 1);
                //printf("result 1: %d \n", fibo(i-1));
                //printf("n:%d \n", n);
                break;
            }
            result += fibo(i-2);
            n -= fibo(i-1);
            //printf("result 2: %d \n", fibo(i-2));
            //printf("n:%d \n", n);
            i =0; 
       }

   }
   return result;
}

int main() {
    long long int n; 
    char str[100]; 
    scanf("%s", str);
    n = atoi(str);
    long long int res = chi(n);
    printf ("%d",res);
    return 0;
}