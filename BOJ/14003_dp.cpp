#include<bits/stdc++.h>
using namespace std;
long long int A[1000000];
long long dp[100000];//index 저장
int n; 
vector <int> v[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    for(int i=0; i<n; i++){
        dp[i] = 1;
    }

    int max_index = 0;
    for(int i=0; i<n; i++){
        int compare = A[i];
        for(int j =0; j<i; j++){
            if(A[i] > A[j]){
                dp[i]++;
                v[i].push_back(A[j]);
            }
        }
        if(dp[max_index] < dp[i]) {max_index = i;}
    }
    
    cout << dp[max_index] << endl;
    for(auto node : v[max_index]){
        cout << node << " ";
    }
    cout << A[max_index] << endl;

    return 0;
}