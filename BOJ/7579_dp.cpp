#include <iostream>
#include <algorithm>
using namespace std;

long long int memory[101];
int cash[101];
long long int DP[102][10001];
long long int M,N;

int main(){
	ios_base::sync_with_stdio(false);
    cin >> N >> M;    
    for(int i=1; i<=N; i++){
        cin >> memory[i];
    }
    for(int i=1; i<=N; i++){
        cin >> cash[i];
    }

int result = 1000000000; 
    for(int num=1; num<=N; num++){
        for(int cost =0; cost<=10000; cost++){
            if (cash[num] <= cost){
                DP[num][cost] = max(DP[num-1][cost], DP[num-1][cost-cash[num]] + memory[num]);
            }else {
                DP[num][cost] = DP[num-1][cost];
            }
            if(DP[num][cost] >= M) {result = min(result, cost);}
            //cout << DP[num][cost] << " ";
        } 
        //cout << endl;
    }
    
    cout << result << endl;
    return 0;
}