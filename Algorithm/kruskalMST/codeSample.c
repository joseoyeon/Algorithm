#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10000
#define DOT_NUM 100

void input_quiz(int(*quiz)[3], const char *fileDir);

void main()
{
	char *fileDir = "./quiz_4.csv";
	int quiz[SIZE][3];
	int weight_sum = 0;

	// write your var
	
	input_quiz(quiz, fileDir);

	// write bubble sorting code


	// print 6712th weight
	printf("6712th dot's weight : %d\n", a);

	// write kruskal MST code
	
			printf("%d th , %d", b, c);
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