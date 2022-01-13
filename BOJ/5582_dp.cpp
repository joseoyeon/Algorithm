#include<iostream>
#include<string>
#include<vector>
using namespace std;
string s1,s2;
string one[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	cin >> s1;
	cin >> s2;

    for(int i=1; i<=s1.length(); i++){ // s1은 기다란거 
        for(int j=1; j<=s2.length(); j++){
             if(s1[i-1] == s2[j-1]){
                one[i][j] = one[i-1][j-1] + s1[i-1]; 
            }else {
                if(one[i-1][j].length() >=  one[i][j-1].length()){
                     one[i][j] = one[i-1][j];
                } else {
                    one[i][j] = one[i][j-1];
                }
            }
        }
    }

    printf("%d\n", one[s1.length()][s2.length()].length());
    cout << one[s1.length()][s2.length()] << endl;
    return 0;
}