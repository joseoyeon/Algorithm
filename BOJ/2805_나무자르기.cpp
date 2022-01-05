#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long int n,m, min, max, mid, temp = 0;
    cin >> n >> m;
    unsigned long long int trees[n];
    for(int i=0; i<n; i++) {
        cin >> trees[i];
        if(trees[i]>=max) max = trees[i];
    }
    while(min <= max) {
        temp = 0;
        mid = (min +max)/2;
        for(int i=0; i<n; i++) if(trees[i]>mid) temp += trees[i]-mid;
        if(temp>=m) min = mid +1;
        else if(temp < m) max = mid -1;
    }
    cout <<max << endl;
    return 0;
}