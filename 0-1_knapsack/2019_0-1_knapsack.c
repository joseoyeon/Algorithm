#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DATA_SIZE 1000
#define CAPACITY 10000
#define COLUMN_NUM 2

void read_data(int(*quiz)[COLUMN_NUM], const char* fileDir);

int main()
{
	char* fileDir = "./0-1_knapsack.csv";
	int data[DATA_SIZE][COLUMN_NUM];
	int total_value = 0;

	read_data(data, fileDir); // CSV data file read

	// write your code here

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