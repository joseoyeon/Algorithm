#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define OX 80

int OX_num(char *ox){
    int count =0;
    int score=0;
    
    for(int i=0; ox[i]; i++){
        if(ox[i] == 'O'){  
            count++;        
            score += count;
        }else{
            count = 0;
            }
        }
return score;
}

int main(){
    int n;
    int i;
    int score[100]; 
    char ox[OX]={};

    scanf("%d",&n);
    for(i= 0; i<n; i++){
        scanf("%s", ox);
        score[i]= OX_num(ox);
    }
    
    for(i=0; i<n; i++)printf("%d\n",score[i]);
    return 0;
}