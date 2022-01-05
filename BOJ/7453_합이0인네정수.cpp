#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;

int arr[4001][4];
vector<int> A, B;
long long answer = 0;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < 4; j++) cin >> arr[i][j];


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A.push_back(arr[i][0] + arr[j][1]);
			B.push_back(arr[i][2] + arr[j][3]);
		}	
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	for (int i = 0; i < A.size(); i++) {
		
		int B_pre = lower_bound(B.begin(), B.end(), -A[i]) - B.begin();
		int B_end = upper_bound(B.begin(), B.end(), -A[i]) - B.begin(); // find index

		answer += (B_end - B_pre);
	}

	cout << answer << endl;
	
	return 0;

}