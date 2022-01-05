#include <iostream>
#include <cmath>
using namespace std;
char tree[26];
long long arr[1000001];

char init (int node_index, char node, char left, char right) {
    if (node == arr[node_index]) {
        tree[node + 1] = left;
        tree[node + 2] = right;
    }
}

char pre(int node_index, int left, int right) {
    return
}
char mid(int node_index, int left, int right) {
    return
}
char last(int node_index, int left, int right){

}
int main() {
    int n; cin>>n;
    int height = ceil(log2(n));
    cout << height <<endl;
    int node = 0;
    cin >> tree[0]; // A
    for(int node=1;node<height;node++){
        int b; cin >> b;
        cin >> tree[2*node];
        cin >> tree[2*node+1];    
    }

    for(int i =0; i< n; i++) {
        cout << tree[i] << " " ;
    }
    return 0;
}