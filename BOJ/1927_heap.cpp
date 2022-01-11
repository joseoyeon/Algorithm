#include<bits/stdc++.h>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n; cin >> n;
    for(int i=0; i< n; i++){
        int x; cin >> x;  
        if (x == 0) { 
            if (pq.empty()) {cout << 0 << endl;}
            else {cout << pq.top() << endl;pq.pop();}
            }
        else{
            pq.push(x); 
        }
    }
    return 0;
}