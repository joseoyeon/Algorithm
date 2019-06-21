#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DATA_SIZE 200
#define CAPACITY 1000
#define COLUMN_NUM 2

void read_data(int(*quiz)[COLUMN_NUM], const char* fileDir);
int knapsack(int(*data)[COLUMN_NUM]);

int main()
{
	char* fileDir = "./0-1_knapsack.csv";
	int data[DATA_SIZE][COLUMN_NUM];
	int total_value = 0,tmp=0;

	read_data(data, fileDir); // CSV data file read

	total_value = knapsack(data);

	printf("Total value: %d\n", total_value); // result format

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

int knapsack(int(*data)[COLUMN_NUM]) { //data[v][w]
    int K[DATA_SIZE][CAPACITY]; // item: datasize 개
    int i=0,w=0,C=0;

for (i = 1; i < DATA_SIZE; i++) {K[i][0] = 0;}// Bag capacity 0
for (w = 0; w< CAPACITY; w++) {K[0][w]=0;} // item 0

for (i = 0; i<DATA_SIZE;  i++){ 
    for (w = 1; w< CAPACITY; w++) { 
        if ( data[i][1] > w )  
            {K[i][w] = K[i-1][w];}
        else {
            K[i][w] = (K[i-1][w] > (K[i-1][w-data[i][1]] + data[i][0])) ? K[i-1][w] : K[i-1][w-data[i][1]] + data[i][0];
            }
        }
    }
    return K[DATA_SIZE-1][CAPACITY-1];
}