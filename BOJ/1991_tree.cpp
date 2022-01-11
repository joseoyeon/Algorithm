#include<bits/stdc++.h>
using namespace std;

struct node{
    char left;
    char right;
};
vector<node> v(26);

void pre(char node) {
    if (node == '.') return; 
    cout << node ;
    pre(v[node].left);
    pre(v[node].right);
}

void in(char node) {
    if(node == '.') return;
    in(v[node].left);
    cout << node;
    in(v[node].right);
}

void post(char node) {
    if(node == '.') return; 
    post(v[node].left);
    post(v[node].right);
    cout <<node ;
}
int main(){
    int n; 
    cin >> n; 

    char right, left, root; 
    for (int i=0; i<n; i++) {
        cin >> root >> left >> right;
        v[root].left = left; 
        v[root].right = right;
    }
    pre('A');
    cout << endl;

    in('A');
    cout << endl;

    post('A');
    cout << endl;
    return 0;
}