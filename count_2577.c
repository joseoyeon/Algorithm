#include<stdio.h>

int main() {
    int num[11]={0};
    int A,B,C =0;
    int i=0;
    scanf("%d",&A);
    scanf("%d",&B);
    scanf("%d",&C);
    
    num[11] = A*B*C;

    while (num[11] !=0 ){
    num[num[11]%10]++;
    num[11] /=10;  
    }
    
    while(i != 10){
        printf("%d\n", num[i]);
        i++;
    }
    
    return 0;
}