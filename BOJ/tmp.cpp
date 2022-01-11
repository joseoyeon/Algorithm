#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int v,e;
    scanf("%d %d",&v,&e);
    vector <int> v[v]; 

    while(e--) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int node[v+1];
    for(int i=1; i<=v; i++) {node[i]=i;}
    
    while(true) {
        bool flag = false; 
        for(int i=1; i<=n; i++) {
            if(node[i] == i) {flag = true;}
        }
        if(!flag) {break;}

        
    }

}