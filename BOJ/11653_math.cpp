#include<bits/stdc++.h>
using namespace std;
int check[10000000];

int main() { 
    int n;
    cin >> n;
    while(n!=1) { 
        // 에라토스테네스의 체를 구현하면서 소수로 나누어서 나머지가 0이면 n/=prime 을 하면된다.   
        for(int i= 2; i*i <=n; i++) {
            if(check[i] == 0){ if(n%i == 0) {n /= i; cout << i << endl;}} 
            for(int j = i*2; j<=n; j++) {
                check[j] = 1; // 소수가 아니다...
            }
        }
    }
    return 0;
}