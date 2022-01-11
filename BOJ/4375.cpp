#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    while (cin >> n) {
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            tmp = tmp * 10 + 1;
            tmp %= n;
            if (tmp == 0) {
                cout << i << "\n";
                break;
            }
        }
    }
}