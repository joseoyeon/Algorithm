#include<iostream>
using namespace std;

int min(int a, int b) {if(a>b) return b; return a;}
int N,S;

int main() {
        cin >> N >> S; 
        int num[N];
        for(int i=0; i<N; i++){cin >> num[i];}

        int left =0,right = 0;
        int sum = num[0];
        int answer = 100000;
        while(left <= right && right < N){
                if (sum < S) {sum += num[++right];}
                else if (sum == S) {
                        answer = min(answer, (right - left +1));
                        sum += num[++right];
                }
                else if(sum > S) {
                        answer = min(answer, (right - left +1));
                        sum -= num[left++];
                }
        } 
        if (answer== 100000) {cout << 0 << endl;}
        else {cout << answer << endl;}
        return 0;
}