#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DATA_SIZE 1000
#define CAPACITY 10000
#define COLUMN_NUM 2

void read_data(double(*quiz)[COLUMN_NUM], const char* fileDir);
double Knapsack(double (*data)[COLUMN_NUM]);

int main()
{
	char* fileDir = "./data.csv";
	double data[DATA_SIZE][COLUMN_NUM];
	double total_value = 0;

	read_data(data, fileDir); // CSV data file read

    total_value = Knapsack(data);

	printf("Total value: %f\n", total_value); // result format

}

void read_data(double(*quiz)[COLUMN_NUM], const char* fileDir)
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


double Knapsack(double (*data)[COLUMN_NUM]) {
    double total_value=0,w=0,v=0,temp;
    int i=0; 
    double sortlist[DATA_SIZE][2];


//단위 무게당 가치를 계산. data 0: 가치 1: 무게 // sortlist 0 : 단위 무게당 가치 1: 무게
    for (i=0; i<DATA_SIZE; i++){
        sortlist[i][0] = (double)(data[i][0]/data[i][1]);
        sortlist[i][1] = data[i][1];
        }

//버블 정렬
for(int j=0; j<DATA_SIZE; j++){
    for(i=0; i<j; i++){
        if(sortlist[i][0] < sortlist[i+1][0]){
            temp = sortlist[i][0];
            sortlist[i][0]= sortlist[i+1][0];
            sortlist[i+1][0] = temp;

            temp = sortlist[i][1];
            sortlist[i][1]= sortlist[i+1][1];
            sortlist[i+1][1] = temp;
        }
    }
}

    i=0;
    while (w+sortlist[i][1] <= CAPACITY){
        w += sortlist[i][1];
        total_value += (double)(sortlist[i][0]*sortlist[i][1]);
        i++;
    }
    if( (CAPACITY-w) > 0){//일단 w를 업데이트 시키지 말고 계산해야 한다. 아니면 (CAPACITY-w) 0 나옴 
        total_value += (double)((CAPACITY-w)*sortlist[i][0]);
        w += (CAPACITY-w);
    }
    return total_value;
}
