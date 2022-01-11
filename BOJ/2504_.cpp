#include<bits/stdc++.h>
#include<stack>
#include<string>
using namespace std;
stack <char> st;
string str;

int main(void)
{
    cin >> str;
    long long result = 0;
    int temp = 1;
    bool impossible = false;

    for (int i = 0; i < str.size(); i++) {
        if(str[i] == '(') {temp *= 2;st.push('(');}
        else if (str[i] == '['){temp *= 3;st.push('[');}
        else if (str[i] == ')' && (st.empty() || st.top() != '(')) {impossible = true; break;}
        else if (str[i] == ']' && (st.empty() || st.top() != '[')){impossible = true;break;}
        else if (str[i] == ')'){
                if (str[i - 1] == '('){result += temp;}
            st.pop();
            temp /= 2;
        }
        else if (str[i] == ']') {
            if (str[i - 1] == '['){result += temp;}
            st.pop();
            temp /= 3;
        }
    }

    if (impossible || !st.empty())
        cout << 0 << "\n";
    else
        cout << result << "\n";
    return 0;
}