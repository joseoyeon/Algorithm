#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10000
#define DOT_NUM 100

void input_quiz(int(*quiz)[3], const char *fileDir);
int kruskalMST(int (*quiz)[3], int *weight_sum);
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

        dot1 = group[quiz[count][0]];
        dot2 = group[quiz[count][1]];
        if(dot1 != dot2){ 

            if( dot1 < dot2) {
            for (int i=0; i<DOT_NUM;i++){
                if(group[i] == dot2){group[i] = dot1;}}
            }
            else {
               for (int i=0; i<DOT_NUM;i++){
                if(group[i] == dot1){group[i] = dot2;}}
                }
            *weight_sum += quiz[count][2];
        }
        count++;
    }
    return count;
}
/*
버블 정렬로 가중치가 낮은 것순대로 정렬했으니까.순서대로 넣어주면 된다.
생각해보면 일단 각 점마다 고유의 그룹을 부여하고
하나의 그룹이 될때까지 반복한다.
각 점의 그룹 주소를 받아서 같은 그룹에 속했으면 건너 뛰고 다른 그룹에 속해 있으면 작은 그룹 번호로 바꾸고 가중치를 더한다.
이 과정에서 가장 중요한 함수는 getGroupNumber인데 자기 자신의 인덱스가 그룹 번호면 반환하고 
자신의 인덱스(점 번호)가 그룹 주소와 같지 않다면 그룹 주소와 같은 인덱스를 가진 점을 찾아간다.
자기 자신의 인덱스가 그룹주소인 것을 찾으면 그 과정을 거친 점들에게 그룹 주소를 재귀함수로 반환하면서 그룹주소가 잘못된 점(dot)들을 고친다(그룹주소 업데이트).
 */