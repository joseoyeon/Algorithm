#include<bits/stdc++.h>
#include<algorithm>
using namespace std; 
#define MAX 1001

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
int table[16] = {0,};
vector <pair<int,int>> map; 
int T,P,n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &T, &P);
        if (T+i <= n) { 
            map.push_back(make_pair(T,P));
        } else{
            map.push_back(make_pair(0,0));
        }
    }

    for(int i=0;i<n;i++){
        table[i] = map[i].second;
    }
    
    int max = 0;
    for(int cur=n-1; cur>=0; cur--){
        if (map[cur+1].second > map[cur].second + map[cur + map[cur].first].second){
            table[cur] = table[cur+1];
        } else {
            table[cur] = table[cur] + table[cur + map[cur].first];
        }
        if(table[cur] > max) {
            max = table[cur];
        }
    }

    printf("%d", max);
    return 0;
}