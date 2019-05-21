#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define E 15
#define S 28
#define M 19

//  역원 구하기
int gcd(int a, int m)
{   unsigned long long i,x=1;
    for (int i=1; i<m; i++) {
    if ((a*i) % m == 1) {
        x = i;
    }
    }
    return x;
}

int main(){
    int remainder[3];
    int year ;
    for (int i=0; i<3; i++){
        scanf("%d", &remainder[i]);
    }
    year = ((E*M*gcd(E*M,S)*remainder[1]) + (S*E*gcd(S*E,M)*remainder[2]) +(M*S*gcd(M*S,E)*remainder[0])) % (E*S*M) ;
    printf("%d",year); 
    return 0;
}