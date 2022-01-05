#include<iostream>
using namespace std;

int min(int a, int b) {if(a>b) return b; return a;}
unsigned long long int N; 
int main() {
    cin >> N; 
    unsigned long long int run[N];
    unsigned long long int final[N];
    for(int i=0; i<N; i++) {cin >> run[i];}

    for(int i=0; i< N; i++) {
        final[i] = 1; // 등수 
        for(int j=0; j<i; j++) {
            if(run[i] < run[j]) { final[i]++;} // 앞에 있는게 실력이 더 우수하다면 ++ 한다. 
        }
    }

    // 출력
    for(int i =0; i<N;i++) {
        cout << final[i] << endl;
    }


    return 0;
}