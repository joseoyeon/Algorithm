#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS

int min(int n, int m){
    return n<=m? n:m;
}

int main () {
    int x,y,w,h,s =0;
    scanf("%d %d %d %d",&x, &y, &w, &h);
    s= min(h-y,(min(min(x,y),w-x)));
    printf("%d",abs(s));
    return 0;
} a