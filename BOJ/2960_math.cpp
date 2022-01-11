#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
int num[MAX] = {0,};

int main() {
    int N,K;
    cin >> N >> K;
    int index=0;
     for (int prime = 2; prime <= N; prime++) { 
        if (num[prime] == 1) { continue;}

        for (int j = prime; j <= N; j += prime) {
            if(num[j] == 0) {index++;  num[j] = 1;}
            if(index == K) {cout << j << endl; exit(0);}
        }

    }

    return 0;
}