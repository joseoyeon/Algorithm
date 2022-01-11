#include<iostream>
using namespace std;

int main() {
    int n; cin >>n;
    int prime[n];
    bool check[n];  // false : 소수 true : 소수 아님
    check[1] = true;
    check[0] = true; 
    int index =0;
    //에라토스 테네스의 채
    for(int i=2; i<= n; i++) {
        if(check[i]) {continue;} 
        if(check[i] == false) {prime[index++] = i;}
        for(int j=i*2; j<=n; j+=i){
            check[j] = true; // 소수 아님 
        }
    }


    for(int i=0; i<index-1; i++) {cout << prime[i] << " "; }
    int sum,count =0;
    int start=0, end=0;
    while(end <= n){
        cout << start << " " << end << " " << sum << endl;
        if(sum > n) {sum -=prime[start++]; }
        else if (sum < n) {sum+=prime[end++];}
        else if (sum ==n) {count ++; sum -=prime[start++];}
        if (end >= n && start >= n) {break;}
        if(end < start) {break;}
    }
    cout << count << endl;
    return 0;
}