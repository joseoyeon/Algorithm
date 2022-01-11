
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, H;
vector<int> A;
vector<int> B;

int main()
{

	scanf("%d %d",&N, &H);

	int inp1, inp2;

	for(int i=0;i<N/2;i++){
		scanf("%d %d",&inp1, &inp2);
		A.push_back(inp1);
		B.push_back(inp2);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int ans = 100000000;
	int cnt = 0;
	int ret;
	for(int i=1; i<=H;i++){
		ret = N/2 - (lower_bound(A.begin(), A.end(), i) - A.begin());
		ret += N/2 - (upper_bound(B.begin(), B.end(), H-i) - B.begin());

		if(ret < ans){
			ans = ret;
			cnt = 1;
		}else if(ret == ans){
			cnt++;
		}
	}

	printf("%d %d\n", ans, cnt);

	