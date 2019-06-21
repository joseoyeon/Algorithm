#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define DATANUM 10495

int main(void)
{
	FILE* fp;
	int i,j = 0;
	char data_1 = 0;
	int cnt = 0;
	int filenum = 0;
	char buf[16] = { 0, };

	fp = fopen("./data.csv", "r");

	if (fp == NULL)
		puts("file open failed");
	else
	{
		i = 0;
		while (fscanf(fp, "%c", &data_1) != EOF)
		{
			if ((data_1 == ',') || (data_1 == '\n'))
			{
				cnt++;
				i = 0;
				puts(buf);
			}
			else
			{
				buf[i] = data_1;
				i++;
			}
		}
	}

	fclose(fp);

	return 0;
}




