#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define DATA_SIZE 150
#define COLUMN_NUM 4
#define K 3 

void read_data(double(*quiz)[COLUMN_NUM], const char* fileDir);
void printcenter(double(*center)[COLUMN_NUM]);
double distance (double (*A), double (*B));
int redcenter(double (*Ocenter)[COLUMN_NUM],double(*Ncenter)[COLUMN_NUM]);

int main()
{
	char* fileDir = "./iris.csv";
	double X[DATA_SIZE][COLUMN_NUM]; //dot
	read_data(X, fileDir); // CSV data file read
//printf("%f %f %f %f", data[0][0],data[0][1],data[0][2],data[0][3]);
  
   /*init Clusters*/
    double Ocenter[K][COLUMN_NUM]={0,};// 랜덤하게 선택된 센터 : 예전값
    double Ncenter[K][COLUMN_NUM]={0,}; // 새로운 센터 값
    int Kx[DATA_SIZE]={0,};// i 번째 점이 속한 클러스터 값
    int i,j,k;

   // 1. k개의 임의의 센터를 정한다.
       for (k=0;k<K; k++){
            i = rand()%DATA_SIZE;
        for(j=0; j<4; j++){
            Ocenter[k][j] = X[i][j];
            Ncenter[k][j] =0;
         }
       }
    printcenter(Ocenter);
    printf("\n");

while (1){
    //2. 각각의 클러스터에 대해 거리를 구하고 점들은 가장 가까운 곳의 클러스터에 속하게 한다. 
    double a,b,c;

    for (i=0; i<DATA_SIZE; i++){
        a= distance(Ocenter[0], X[i]);
        b= distance(Ocenter[1], X[i]);
        c= distance(Ocenter[2], X[i]);

      if (a< b){
          if(c < a){
              Kx[i]=2;
          }
          else{ 
              Kx[i] = 0;
          }
      }
      else{
       if(c < b){
              Kx[i]=2;
          }
          else{ 
              Kx[i] = 1;
          }
      }
    }

    // 3. 평균값을 새로운 Ceter로 정한다. 
    int count[K]= {0,};
    for (i=0 ; i<DATA_SIZE; i++){
        switch(Kx[i]) {
         case 0 : 
            Ncenter[0][0] += X[i][0];
            Ncenter[0][1] += X[i][1];
            Ncenter[0][2] += X[i][2];
            Ncenter[0][3] += X[i][3];
            count[0] ++;
            break;
         case 1 :
            Ncenter[1][0] += X[i][0];
            Ncenter[1][1] += X[i][1];
            Ncenter[1][2] += X[i][2];
            Ncenter[1][3] += X[i][3];
            count[1] ++;
            break;
         case 2 : 
            Ncenter[2][0] += X[i][0];
            Ncenter[2][1] += X[i][1];
            Ncenter[2][2] += X[i][2];
            Ncenter[2][3] += X[i][3];
            count[2] ++;
            break;
         }
    }

    for (i=0; i<K; i++) {
        for(j=0; j<COLUMN_NUM; j++){
            Ncenter[i][j] = Ncenter[i][j]/(double)count[i];
        }
    }
        printf("new center : \n");
        printcenter(Ncenter);
    if(redcenter(Ocenter,Ncenter)) break;// 새 센터가 이전 센터랑 같으면 멈춘다.
    
    /*OLD는 C NEW는 C*/
    for (i=0; i<K; i++) {
        for (j=0; j<COLUMN_NUM; j++){
        Ocenter[i][j] = Ncenter[i][j];
        }
    }
    printf("\n\n");
}
//    printcenter(Ncenter);
	return 0;
}

double distance (double (*A), double (*B)){
    double tmp = sqrt((A[0]-B[0])*(A[0]-B[0])+(A[1]-B[1])*(A[1]-B[1])+(A[2]-B[2])*(A[2]-B[2])+(A[3]-B[3])*(A[3]-B[3]));
    return tmp;
}

void printcenter(double(*center)[COLUMN_NUM]){
    int i,j;
    for(j=0; j<K; j++){
        for (i=0; i<COLUMN_NUM; i++){
            printf("%0.1f ", center[j][i]);
        }
        printf("\n");
    }
}

int redcenter(double (*Ocenter)[COLUMN_NUM], double(*Ncenter)[COLUMN_NUM]){
    int i,j;
    for (i=0; i<K; i++){
        for (j=0; j<COLUMN_NUM; j++){
            if(Ocenter[i][j] != Ncenter[i][j])
                return 0;
        }
    }
    return 1;
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
	fclose(fp);}
