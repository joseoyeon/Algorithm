#include<iostream>
#include<string>
#include<vector>
using namespace std;

string s1;
string s2;
string LCS[1001][1001];

int main()
{
	cin >> s1;
	cin >> s2;

	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i-1] == s2[j-1])
			{	// 왼쪽 대각 위의 LCS에서 이어 붙히기
				LCS[i][j] = LCS[i-1][j-1] + s1[i-1];
			}
			else
			{	// 왼쪽 LCS와 위쪽 LCS중 긴 LCS를 가져오기
				if(LCS[i-1][j].length() >= LCS[i][j-1].length())
					LCS[i][j] = LCS[i-1][j];
				else // (LCS[i-1][j] < LCS[i][j-1])
					LCS[i][j] = LCS[i][j-1];
			}
		}
	}

	cout << LCS[s1.length()][s2.length()].length() << '\n';
	cout << LCS[s1.length()][s2.length()] <<'\n';


}