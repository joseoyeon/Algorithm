# include<stdio.h>

void quitckSort(int *data, int start, int end){
    if (start >= end) {
        return ;
    } 
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;

    while (i <= j){
        while (i <= end && data[i] < data[key]){i++;}
        while (j > start && data[j] >= data[key]){j--;}
        if(i > j) {
            temp = data [j];
            data[j] = data[key];
            data[key] = temp;
        }else {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    } 
    quitckSort(data, start, j-1);
    quitckSort(data, j+1, end);
}

int main() {
    int a[10000001];
    int num;
    int temp;

    scanf("%d",&num);

    for (int i=0; i<num; i++) {
        scanf("%d", &a[i]);
    }
    
    quitckSort(a, 0, num-1);

    for (int i = 0; i<num; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}