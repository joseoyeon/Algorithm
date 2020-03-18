
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

int main(void)
{
	FILE *ansP;
	unsigned int data1[4] = { 0xDAC1A3A4, 0x1305DC93, 0x45086119, 0xD66A3A39 };
	unsigned int data2[4] = { 0xD94B0DCB, 0x81896E34, 0xC649CEF6, 0x5DBDD571 };
	unsigned int ans_1[5] = { 0, }, ans_2[4] = { 0, }, ans_3[8] = { 0, };
	int i = 0;

	//write your code

	ansP = fopen("./ans.csv", "w");

	for (i = 0; i < 5; i++)
		fprintf(ansP, "%08X", ans_1[i]);
	
	fputs("\n", ansP);
	
	for (i = 0; i < 4; i++)
		fprintf(ansP, "%08X", ans_2[i]);

	fputs("\n", ansP);

	for (i = 0; i < 8; i++)
		fprintf(ansP, "%08X", ans_3[i]);

	fclose(ansP);

	system("anscheck.exe");

	return 0;
}
