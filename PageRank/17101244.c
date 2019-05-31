#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 10495
#define COLUMN_NUM 2
#define IP_Length 16
#define D 0.99
#define ITERATION 100
#define N 932

void read_data(char(*quiz)[IP_Length] , const char* fileDir);
void PageRank(char(*data)[IP_Length]);

int main()
{
	char* fileDir = "./data.csv";
	char data[DATA_SIZE*COLUMN_NUM][IP_Length] ;
	clock_t start,end;

	read_data(data, fileDir); // CSV data file read

	start = clock();
    PageRank(data);
	end = clock();

	printf("time: %d(s)\n", (end-start)/1000); // result format

}

void read_data(char(*quiz)[IP_Length], const char* fileDir)
{
	FILE* fp;
	char buffer[DATA_SIZE*COLUMN_NUM];
	char* ptr;
	int i = 0, j = 0, p=0;

	fp = fopen(fileDir, "r");

	if (fp == NULL)
	{
		puts("data file open failed!!");
		return;
	}

	for (i = 0; i < DATA_SIZE; i++)
	{   
		fgets(buffer, DATA_SIZE * COLUMN_NUM, fp);
        ptr = strtok(buffer, ", \n");
		j=0;

		while (ptr != NULL)
		{
			for(p=0; p <IP_Length; p++)
            	quiz[i*COLUMN_NUM+j][p] = ptr[p];
			ptr = strtok(NULL, ", \n");
			j++;
		}
		 printf("%s | %s |\n",quiz[i*COLUMN_NUM+0],quiz[i*COLUMN_NUM+1]);
	}

	fclose(fp);
}

void PageRank(char(*data)[IP_Length]){
	double PR[N]; //  i 정보의 rank value
	int C[N]; // i 정보가 가지고 있는 Out-bound Link들의 개수
	int IN[N];
	int i=0,j=0;

	/*초기화*/
	for(i=0; i<N;i++){
		PR[i] = (1-D)/N;
		C[i] = 0;
		}

	/*실행*/
	// for(i=0; i<ITERATION; i++) {
	// 	for(j=0; j < N; j++){
	// 		/*IN을 어떻게 찾느냐면 */
	// 		PR[i] = (1-D)/N + D*(PR[IN[i]]/C[IN[i]] +PR[IN[i]]/C[IN[i]]+...);
	// 	}
	// }

	/*이제 정렬해서 상위 10개를 찾는다.*/
	/*
	BEST10[10];
	for j 10
		for i N
			BEST10[j] = PR[i] 중에서 최고 찾은 다음 
			PR[i] =0 해버림			
	*/
}