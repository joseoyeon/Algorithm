#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {return a;}
    return gcd(b, a%b);
}
int main() {
    int A,B,C,D; 
    cin >> A >>B;
    cin >> C >> D; 
    int answer1 = A*D + B*C;
    int answer2 = B*D;
    int gd = gcd(answer1, answer2); 

    
    cout << answer1/gd << " " << answer2/gd << endl;
    return 0;
}