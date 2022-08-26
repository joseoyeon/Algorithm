#include<bits/stdc++.h>
using namespace std;
long long int A[10000000];
long long dp[1000000];//index 저장
int n; 
vector <int> V;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    //DP 
    for(int i=0; i<n;i++){
        if(V.size() ==0 || V[V.size()-1] < A[i]){
            V.push_back(A[i]);
            dp[i] = V.size()-1;
        } else {
            // A[i] 자리 찾을 수 있도록 이분 탐색 하기
            int left = 0;
            int right = V.size()-1;
            int mid = 0;

            while(left < right){
                mid = (left+right)/2 ;
                if(V[mid] >= A[i]) { right = mid; }
                else { left = mid+1;} 
            }
            V[left] = A[i];
            dp[i]= left;
        }
    }

    vector <int> result;
    int find = V.size()-1;
    for(int j = n-1 ; j>=0;j--){
        if(dp[j] == find){
            find--;
            result.push_back(A[j]);
        }
    }


    cout << result.size() << endl;
    for(int i =result.size()-1; i>=0; i--){
        cout << result[i] << " ";
    }
    return 0;
}