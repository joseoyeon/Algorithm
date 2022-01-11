#include <bits/stdc++.h>
using namespace std;

int N;
string ss;
map<string, double> dic; 

int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
while(getline(cin,ss)){
	N+=1;
	dic[ss]++;
}
cout<<fixed;
cout.precision(4); 
for (auto iter=dic.begin(); iter!=dic.end();iter++){
	string name = iter->first;
	double n = iter->second;
	n/=N;
	n*=100.0;
	cout << name << ' ' << n << '\n'; 
}
return 0;
}