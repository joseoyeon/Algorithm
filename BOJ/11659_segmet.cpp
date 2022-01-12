#include <bits/stdc++.h>
using namespace std;

int N, M, pSum[100001];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // 입력받으면서 prefix sum을 채움(1칸이 더 필요함에 유의)
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        int A;
        cin >> A;
        pSum[i+1] = pSum[i] + A;
    }
    // s~e 성분 합 = pSum[e] - pSum[s-1]
    for(int i = 0; i < M; ++i){
        int s, e;
        cin >> s >> e;
        cout << pSum[e]-pSum[s-1] << '\n';
    }
}