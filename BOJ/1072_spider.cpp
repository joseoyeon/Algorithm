#include <bits/stdc++.h> 
#define MAX_ 1000000000 
using namespace std; 

typedef long long ll; 

int main() { 
    ll x, y, z, low, high, mid, test_z; 
    cin >> x >> y; 
    z = 100 * y / x; 
    if (z >= 99) {cout << -1; return 0; } 
    low = 0; high = MAX_; 
    while (low <= high) { 
        mid = (low + high) / 2; 
        test_z = 100 * (y + mid) / (x + mid); 
        if (z < test_z) { high = mid - 1; } 
        else { low = mid + 1; } 
        } 
    cout << low; 
    }
