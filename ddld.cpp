
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
 
using namespace std;
 
vector<pair<int, int> > v;
 
int main() {
    int N;
    int a, b;
    double tmp;
    double min = 10000000000;
    cin >> N;

    for (int i = 0; i < N; i++) {
        scanf("%d, %d",&a,&b);
        v.push_back({ a,b });
    }
 
    for (int i = 0; i < v.size(); i++) {
        //cout << v[i].first << " " << v[i].second << "\n\n";
         for (int j = i+1; j < v.size(); j++) {
             //cout << v[j].first << " " << v[j].second << "\n";
            a = v[i].first - v[j].first;
            b = v[i].second -  v[j].second;
            tmp = a*a+b*b;
            if(min > tmp) {min = tmp;}
        }
    }
 
    printf("%.6f", min);
    return 0;
}
