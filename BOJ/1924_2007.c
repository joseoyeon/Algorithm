#include<stdio.h>

int main(){
    int x, y, i=0;
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    char week[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    scanf("%d %d",&x,&y);
   
    if(12<x||x<1 || 31 < y || y<1){printf("input error!"); return -1;}
    for(i=0;i<x-1; i++) y+= month[i];
    printf("%s",week[y%7]);

    return 0;
}