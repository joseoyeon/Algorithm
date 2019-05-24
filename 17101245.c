#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10000
#define DOT_NUM 100

int gcd(int a, int b){
    if(a%b == 0) {return b;}
    else return gcd(b, a%b);
}

void main()
{
    int a,b;
    scanf("%d ", &a);
    scanf("%d ", &b);
	printf("%d %d",gcd(a,b), a*b);

}
