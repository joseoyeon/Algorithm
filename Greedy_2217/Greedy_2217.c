#include<stdio.h>
#define SIZE 100001

int quicksort(int*data, int start, int end){
    if(start >= end){return 0;}
    int key=start, i =start+1, j=end, temp;
    while(i<=j){ //서로 엇갈릴때 까지 반복
        while(data[key] <= data[i] && i <= end){
            i++;
        }
        while(data[key] >= data[j] && j <= start){
            j--;
        }
        if(i>j){
            temp = data[key];
            data[key] = data[j];
            data[j] = temp;
        }
        else {
            temp = data[i];
            data[i] = data[j];
            data[j] = data[i];
        }
    }
    quicksort(data, start, j-1);
    quicksort(data, j+1, end);
}

int main() {
    int a[SIZE];
    int N=0, S=0;
    int tmp=0;
    
    scanf("%d%*c", &N);
 
    for(int i=0; i<N; i++){
        scanf("%d",&a[i]);
    }

    quicksort(a, 0,N-1);
 
    for(int i=N; i>0;i--){
        if(S < a[i]*(i+1)) S = a[i]*(i+1); 
    }
    printf("%d", S);
    return 0;
}