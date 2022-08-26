#include<stdio.h>
#include "stdio.h"
#include<algorithm>
#include<string.h>
#include<iostream>
#include<cstdio>
using namespace std;


int main() {
    char input1[1001];
    char input2[1001];
    char test[1001];
    int sum[1001][1001] ={0,};
    cin >> input1 >> input2;

    
    int top = strlen(input1);
    int left = strlen(input2);

    for(int a=1; a<=top; a++){
        for(int b=1; b<=left; b++){
            if (input1[a-1]== input2[b-1]){
                sum[a][b] = sum[a-1][b-1] + 1;
            }
            else {
                 sum[a][b] = max(sum[a-1][b], sum[a][b-1]);
            }  
         }
    }

    int count = 0;
   for (int i=top; i>=0; i--) {
    if(sum[i][left] ==0){break;}
    for(int j = left; j>=0; j--){
        if(sum[i][j] == sum[i-1][j]){break;}
        if(sum[i][j] != sum[i][j-1]){
            test[count] = input2[j-1];
            left = j-1;
            count ++;
            break;
        }
    }
   }


    printf("%d\n", count);
if (count != 0){
    for(int i= count-1; i>= 0; i--){
        printf("%C", test[i]);
}
}
    return 0;
}