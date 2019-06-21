#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define DATA_SIZE 10000

void linner_search(int target, int *data, int datasize);
void binary_search(int target, int *data, int datasize);
void interp_search(int target, int *data, int datasize);


void main(void) {

   int data[DATA_SIZE];
   FILE *file;
   int target = 77744;
   int i;

   file = fopen("data.csv", "r");

   for (i = 0; i < DATA_SIZE; i++)
   {
      fscanf(file, "%d", &data[i]);
   }

   
   linner_search(target, data, DATA_SIZE);
   binary_search(target, data, DATA_SIZE);
   interp_search(target, data, DATA_SIZE);

   fclose(file);

}


void linner_search(int target, int *data, int datasize) 
{
    int count =0;

    for(int i=0; i<datasize; i++){
        count++;
        if(data[i] == target) {
            printf("linnear_search : %d, %d \n", i+1, count);
           break;
        }
    }
}
void binary_search(int target, int *data, int datasize)
{
    int low=0;
    int mid =0;
    int high = datasize-1;
    int count =0;

    while (low <= high){
        count++;
        mid = (high+low)/2;
        if(data[mid] == target){
            printf("binary_search: %d, %d \n", mid+1, count);
            break;
        }else {
            if(data[mid]>target) {high  = mid-1;}
            else{low =mid +1;}
        }
    }
}
void interp_search(int target, int *data, int datasize)
{
    int count =0;
    int low,mid=0; 
    int high = datasize -1;

    while (low <=high) {
        count ++;

        if(data[high]!=data[low]){
            mid = low +(float)(target-data[low]) * (high-low)/(data[high]-data[low]);
        }else {
            mid =low;
        }

        if(target == data[mid]){
            printf("inter_search: %d, %d\n", mid+1, count);
        break;
        }else if (target <data[mid]){
            high = mid - 1;
        }else {
            low = mid +1;
        }
    }
}