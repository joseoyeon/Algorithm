#include<bits/stdc++.h>
using namespace std;
long tree[1111111];
long race[500001];
int n;

priority_queue <pair<long, int>>pq; 

//펜윅트리 1 업데이트
void update(int i,int t) {
    while (i <= n) { tree[i]++; i += i & -i; }
}
 
//펜윅트리 합
long sum(int i) {
    long s = 0;
    while (i) { s += tree[i]; i -= i & -i; }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int input;
    for(int i=1;i<=n;i++){
        cin >> input;
        pq.push(make_pair(input,i));// 빠른 순으로 정렬을 한다. speed, index 
        tree[i]=0;
    }

    while(!pq.empty()) {
        long speed = pq.top().first;
        int index = pq.top().second;
        pq.pop();

        update(index,1);
        race[index] = sum(index);
    }

    for(int i=1;i<=n;i++){
        cout << race[i] << endl;
    }

    return 0;
}