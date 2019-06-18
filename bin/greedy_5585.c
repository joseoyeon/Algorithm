#include<stdio.h>

int main() {
    int Num=0, tmp=0;
    int N[1000] = {0,};

    scanf("%d%*c",&Num);
    for(int i=0; i<Num; i++) {
        scanf("%d",&N[i]);
    }

    //bubble sort
    for(int j=0; j<Num; j++){
        for(int i=0; i<Num-1; i++){
            if(N[i] > N[i+1]) {
                tmp = N[i];
                N[i] = N[i+1];
                N[i+1] = tmp;
            }
        }
    }

    tmp =0;
    //대기 시간을 곱한다.
    for(int i=Num; i>=0; i--)    
        {tmp += N[Num-i]*i;}
    
    printf("%d",tmp);
    return 0;
}