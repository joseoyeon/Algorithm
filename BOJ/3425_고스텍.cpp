#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int ABS_MAX = 1e9;
enum OPERATION {NUM, POP, INV, DUP, SWP, ADD, SUB, MUL, DIV, MOD};

inline int opidx(string s) {
	if (s == "NUM") return NUM;
	else if (s == "POP") return POP;
	else if (s == "INV") return INV;
	else if (s == "DUP") return DUP;
	else if (s == "SWP") return SWP;
	else if (s == "ADD") return ADD;
	else if (s == "SUB") return SUB;
	else if (s == "MUL") return MUL;
	else if (s == "DIV") return DIV;
	else if (s == "MOD") return MOD;
	
	static_assert(1);
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);


	string op;
	while (1) {
		vector<pair<int, int>> ops;	// operation, operand
		while (cin >> op) {
			if (op == "QUIT") return 0;

			int operand = 0;
			if (op == "END") break;
			if (op == "NUM") cin >> operand;
			ops.emplace_back(opidx(op), operand);
		}

		int n;
		cin >> n;
		while (n--) {
			int in;
			cin >> in;

			stack<int> st;
			st.push(in);


			// check
			// 1. overflow
			// 2. stack size
			// 3. div/mod by zero
			bool error = false;
			for (auto&& [op, operand] : ops) {
				if (error) break;

				switch (op) {
				case NUM:
					st.push(operand);
					break;

				case POP:
					if (st.empty()) error = true;
					else st.pop();
					break;

				case INV:
					if (st.empty()) error = true;
					else {
						auto tmp = st.top(); st.pop();
						st.push(-tmp);
					}
					break;

				case DUP:
					if (st.empty()) error = true;
					else st.push(st.top());
					break;

				case SWP:
					if (st.size() < 2) error = true;
					else {
						auto a = st.top(); st.pop();
						auto b = st.top(); st.pop();
						st.push(a);
						st.push(b);
					}
					break;

				case ADD:
					if (st.size() < 2) error = true;
					else {
						auto a = st.top(); st.pop();
						auto b = st.top(); st.pop();
						if (abs(a + b) > ABS_MAX) error = true;
						else st.push(a + b);
					}
					break;

				case SUB:
					if (st.size() < 2) error = true;
					else {
						auto a = st.top(); st.pop();
						auto b = st.top(); st.pop();
						if (abs(b-a) > ABS_MAX) error = true;
						else st.push(b-a);
					}
					break;

				case MUL:
					if (st.size() < 2) error = true;
					else {
						ll a = st.top(); st.pop();
						ll b = st.top(); st.pop();
						if (abs(a*b) > ABS_MAX) error = true;
						else st.push(a*b);
					}
					break;

				case DIV:
					if (st.size() < 2) error = true;
					else {
						auto a = st.top(); st.pop();
						auto b = st.top(); st.pop();
						if (a==0) error = true;
						else {
							int neg_cnt = (a < 0) + (b < 0);
							st.push((abs(b) / abs(a)) * (neg_cnt % 2 ? -1 : 1));
						}
					}
					break;

				case MOD:
					if (st.size() < 2) error = true;
					else {
						auto a = st.top(); st.pop();
						auto b = st.top(); st.pop();
						if (a == 0) error = true;
						else {
							st.push(b%a);
						}
					}
					break;
				}
			} // for ops

			if (error || st.size() != 1)
				cout << "ERROR\n";
			else
				cout << st.top() << '\n';
		} // while (n--)
		cout << '\n';
	}

	return 0;
}