#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DATA_SIZE 100
#define COLUMN_NUM 2

void read_data(int(*quiz)[COLUMN_NUM], const char* fileDir);
int mat_chain(int *C);

int main()
{
	char* fileDir = "./data_07.csv";
	int data[DATA_SIZE][COLUMN_NUM];
	int total_count,i = 0;
    int column[DATA_SIZE+1]={0,};
	read_data(data, fileDir); // CSV data file read

	// write your code here
    for(i=0; i<DATA_SIZE; i++) {column[i] = data[i][0];} // colum number save
    column[DATA_SIZE] = data[DATA_SIZE-1][1];
 
    total_count = mat_chain(column);
	printf("Total count: %d\n", total_count); // result format

	return 0;
}

void read_data(int(*quiz)[COLUMN_NUM], const char* fileDir)
{
	FILE* fp;
	char buffer[DATA_SIZE * COLUMN_NUM];
	char* ptr;
	int i = 0, j = 0;

	fp = fopen(fileDir, "r");

	if (fp == NULL)
	{
		puts("data file open failed!!");

		return;
	}

	for (i = 0; i < DATA_SIZE; i++)
	{
		fgets(buffer, DATA_SIZE * COLUMN_NUM, fp);
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

int mat_chain(int *column){
    int S[DATA_SIZE+1][DATA_SIZE+1]; // count save
    int d, i, j, k;

    for (i=1; i<=DATA_SIZE; i++) S[i][i] = 0; // table number: 1 count :0

    for (d = 1; d < DATA_SIZE; d++){ //| | | | 
         for (i = 1; i <= DATA_SIZE-d; i++) { // -------
            j = i + d;
            S[i][j] =__INT_MAX__;
            for (k = i; k < j; k++){
                if (S[i][k]+S[k+1][j]+column[i-1]*column[k]*column[j] < S[i][j]) {
                    S[i][j] = S[i][k]+S[k+1][j]+column[i-1]*column[k]*column[j];
                }
            }
        }
    }
  
    return S[1][DATA_SIZE];
}
