#include<bits/stdc++.h>
using namespace std;
int arr[1000];

int main()
{
    int v,n=0;
    while(getline(cin,v)) {
        cin >> arr[n++];
    }
    int height = ceil(log2(n));// 높이가 나온다. 
    // root == 1 
    // left == 2 
    // left == 4
    // left == 8 
    int index = 1<<height;
    arr[index]

}