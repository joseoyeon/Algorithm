#include<iostream>
#include<vector>
using namespace std;

int quick_sort(int* A, int start, int end) {
    if(start >= end) {return;} 
    int pivot = start; 
    int i = pivot +1;
    int j = end; 
    int tmp ; 
    while(i <= j) {
        while(i<= end && data[i] <= data[pivot]) {i++;}
        while(j > start && data[j] >= data[pivot]) {j--;}

        if(i>j) { // 엇갈림
        tmp = data[j];
        data[j] = data[pivot]; 
        data[pivot] = tmp;
        } else {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
    quick_sort(data, start, j-1); 
    quick_sort(data,j+1, end);
    return ;
}
int main() {
    int N,M; 
    cin >> N; 
    vector <int> A;
    for (int i=0; i<N; i++) {cin >> A[i]; }
    
    // 이분 탐색
    int left, right; 
    while(left <= right) {
        int mid = (left + right) / 2 ; 
        if(A[mid] > )
    }
    cin >> M; 
    vector <int> finder;
    for (int i=0; i<M; i++) {cin >> finder[i];}

    
    return 0;
}