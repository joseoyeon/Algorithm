#include <cstdio>
 
using namespace std;
 
int main() {
    bool chk[1000001];
    chk[0] = true;
    chk[1] = true;
    for (int i = 2; i <= 1000000; i++) {
        if (!chk[i]) {
            for (int j = i*2; j <= 1000000; j += i) {
                chk[j] = true;
            }
        }
    }
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) return 0;
        for (int i = 2; i <= n; i++) {
            if (!chk[i] && !chk[n-i]) {
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
    }
}
