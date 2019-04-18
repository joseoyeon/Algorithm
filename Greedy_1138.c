#include<stdio.h>

int main() {
    int d[11]={0,};
    int count=0, Num=0, x=0;

    scanf("%d", &Num);
    for (int i=1; i<Num+1; i++) {
        scanf("%d", &x);
        count =0;
        for(int j=0; j<Num; j++){
            if(d[j] ==0 && count == x){d[j] =i; break;}
            if(d[j] ==0) count++;
        }
    }
    for(int i=0; i<Num; i++) {
        printf("%d ", d[i]);
    } 
    return 0;
}