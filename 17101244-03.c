#include <stdio.h>
#define _CTR_SECURE_NO_WARINGS

#define BLOCKNUM 11

int hanoiMov(int (*tower)[BLOCKNUM], int from, int tmp,int to, int blockNum);

int main() {
    int tower[3][BLOCKNUM];
    int cnt =0;
    int i=0;

    for (i=0; i<BLOCKNUM; i++){
        tower[0][i] = i;
    }
printf("from     to\n");
    cnt = hanoiMov(tower, 0,1,2, BLOCKNUM);
 printf("move cnt : %d\n", cnt);   
    return 0;
}

int hanoiMov(int (*tower)[BLOCKNUM], int from, int tmp,int to, int blockNum){
 int cnt =0;

 if(blockNum == 1){ 
    cnt++;
    printf("%d    %d\n",from+1,to+1);
 }else{
     cnt++;
     cnt += hanoiMov(tower, from, to, tmp, blockNum-1);
     printf("%d    %d\n",from+1,to+1);
     cnt +=  hanoiMov(tower, tmp, from, to, blockNum-1);
 }
 return cnt; 
}