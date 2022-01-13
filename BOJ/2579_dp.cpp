#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int step[301];
int dp[301];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    for(int i=0; i<n;i++){
        cin >> step[i];
    }

    dp[0] = step[0];
    dp[1] = step[0]+ step[1];
    dp[2] = max(step[0] + step[2], step[2] + step[1]);

    for(int i =3 ; i<n; i++){
        dp[i] = max(dp[i-2] + step[i], dp[i-3] + step[i] + step[i-1]);
    }    
    cout << dp[n-1] << endl;
    return 0;
}