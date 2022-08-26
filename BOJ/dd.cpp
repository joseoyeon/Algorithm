#include<bits/stdc++.h>
#include<algorithm>
using namespace std; 
#define MAX 1001
int n;
int T[15], P[15];
int cache[15];
int solve(int day)
{
    if (day > n) return -987654321;
    if (day == n) return 0;
    int &ret = cache[day];
    if (ret != -1) return ret;
    ret = max(solve(day + 1), solve(day + T[day]) + P[day]);
    return ret;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &T[i], &P[i]);
        cache[i] = -1;
        
    }
    int ret = solve(0);
    printf("%d\n", ret);
    return 0;
}