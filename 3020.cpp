#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 

int main() {
    int N,H;
    int a,b;
    int solve = 200001;
    int same_count =1; 
    vector <int> lower;
    vector <int> upper;
    scanf("%d %d", &N, &H);
    for(int n =0; n<N/2; n++){
        scanf("%d",&a);
        scanf("%d",&b);
        lower.push_back(a);
        upper.push_back(b);
    }
    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    int count =0;
    for(int h=0; h<H; h++){
        count = N/2 - (lower_bound(lower.begin(), lower.end(), h)-lower.begin());
        count += N/2 - (upper_bound(upper.begin(), upper.end(), H-h)-upper.begin());
        if (solve > count){
     same_count =1; 
     solve = count;
    } else if (solve == count ){
        same_count ++;
    }
    }

    printf("%d %d", solve, same_count);
    return 0;
}