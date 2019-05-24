#define _CRT_SECURE_NO_WsRNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 100
void main(){
    FILE*fp;
    char buffer[100*SIZE];
    char *ptr;
    int quiz[SIZE][SIZE];

    int cost_sum =0;
    int from[SIZE]; // select dot
    int i,j,t, s,d,cost=0; // for index, source, destination, cost

    fp =fopen("./quiz.csv","r");

    if(fp == NULL) {
        puts("file open failed!!");
        return;
    }
    for(i=0; i<SIZE; i++){
        fgets(buffer, 100*SIZE, fp);
        ptr =strtok(buffer, ",");
        j=0;

    while(ptr != NULL){
        quiz[i][j] = atof(ptr);
        ptr = strtok(NULL, ",");
        j++;
        }
    }

        from[0] = 0; //first dot is 0

for(i=0; i<SIZE-1; i){
        cost = __INT_MAX__; //big number reset
        //smallest cost add
        for(t=0; t<=i; t++){ 
            for(j=0; j<SIZE; j++){ 
                if (quiz[from[t]][j] > 0 && cost > quiz[from[t]][j] )   
                { cost = quiz[from[t]][j]; s=from[t]; d=j;} 
            }
        }

    from[++i]=d;
    for(t=0; t<i; t++){ quiz[from[t]][d] =0; quiz[d][from[t]]=0;}
    
    printf("%d to %d, cost : %d\n", s, d, cost);
    //printf("%d\n", d); //every dot print
    cost_sum += cost;
    }
    printf("total cost : %d\n", cost_sum);
}