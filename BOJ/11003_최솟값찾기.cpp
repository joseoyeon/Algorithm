#include <stdio.h>
#include <deque>
using namespace std;

typedef struct st {
	int id, val;		// id : 입력받은 순서, val : 값
	st(int id, int val) {
		this->id = id;
		this->val = val;
	}
}node;

int N, L;			// N 숫자 개수, L 최솟값을 구할 범위 (D[i] = A[i-L+1] ~ A[i] 의 최솟값
int i, input;		// i 입력받는 순서, input 입력받은 값
deque<node> deq;	// 앞뒤로 pop이 가능한 deque를 이용 (최대 L개만 갖고 있을 예정)

int main(void) {
	scanf("%d %d", &N, &L);
	for (i = 0; i < N; i++) {
		if (!deq.empty() && deq.front().id <= i - L) deq.pop_front();
		// 새로운 숫자의 입력
		scanf("%d", &input);
		while (deq.size() && deq.back().val >= input) {
			deq.pop_back();
		}
		deq.push_back(node(i, input));
		// 현재 deque의 first 값은 최솟값을 보장함
		printf("%d ", deq.front().val);
	}
	return 0;
}