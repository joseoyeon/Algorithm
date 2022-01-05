#include<bits/stdc++.h>
using namespace std;

long long int N[90];

long long int fibo(int n) {
    if(n==0) {N[n] = 0; return 0;}
    if (n == 1) {N[n] =1; return 1;}
    if (N[n] ==0 && n>1)N[n] = fibo(n-1) + fibo(n-2);
    return  N[n];
}

int main() {
    int k;
    cin >> k;
    cout << fibo(k) << endl;
    return 0;
}