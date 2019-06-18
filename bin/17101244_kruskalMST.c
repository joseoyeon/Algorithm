#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10000
#define DOT_NUM 100

void input_quiz(int(*quiz)[3], const char *fileDir);
int kruskalMST(int (*quiz)[3], int *weight_sum);
int Union_Find(int set[], int x);
int IsOneGroup(int set[]);

void main()
{
	char *fileDir = "./quiz_4.csv";
	int quiz[SIZE][3]; // start end cost
	int weight_sum = 0;
	// write your var 
    int tmp,count;
	
	input_quiz(quiz, fileDir);

	// writme bubble sorting code
    for(int j=0; j<SIZE; j++){
        for (int i=0; i<SIZE-1; i++) {

                if(quiz[i][2] > quiz[i+1][2]){
                    for(int k=0; k<3; k++){
                        tmp = quiz[i+1][k];
                        quiz[i+1][k] = quiz[i][k];
                        quiz[i][k] = tmp;
                    }
                }

        }
    }

	// print 6712th weight
	printf("6712 th dot's weight : %d\n", quiz[6711][2]);

	// write kruskal MST code
	count = kruskalMST(quiz, &weight_sum);
    printf("%d th ", count);
	printf("cost_sum = %d\t \n", weight_sum);
		
}

void input_quiz(int(*quiz)[3], const char *fileDir)
{
	FILE *fp;
	char buffer[SIZE * 3];
	char *ptr;
	int i = 0, j = 0;

	fp = fopen(fileDir, "r");

	if (fp == NULL)
	{
		puts("quiz file open failed!!");

		return;
	}

	for (i = 0; i < SIZE; i++)
	{
		fgets(buffer, SIZE * 3, fp);
		ptr = strtok(buffer, ",");
		j = 0;

		while (ptr != NULL)
		{
			quiz[i][j] = atof(ptr);
			ptr = strtok(NULL, ",");
			j++;
		}
	}

	fclose(fp);
}


int Union_Find(int group[], int x){
      if(group[x] == x) return x;
      else return group[x] = Union_Find(group, group[x]); 
}

int IsOneGroup(int group[]) {
    for(int i=0; i<DOT_NUM; i++){
        if(group[0] != group[i]) return 0;
    }
    return 1;
}

int kruskalMST(int (*quiz)[3] ,int *weight_sum){
    int group[DOT_NUM]={};
    int dot1, dot2, count=0;
     
    for(int i=0; i<DOT_NUM; i++) {
        group[i] = i;
    }

    while(!IsOneGroup(group)){
         dot1 = Union_Find(group,quiz[count][0]);
         dot2 = Union_Find(group,quiz[count][1]);
        if(dot1 != dot2){ 
            if( dot1 < dot2) {group[dot2] = dot1;}
            else {group[dot1] = dot2;}
            *weight_sum += quiz[count][2];
        }
        count++;
    }
    return count;
}
