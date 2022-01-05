#include<iostream>
#include<stack>
#include<string>
using namespace std;

enum st {push, pop, size, empty, top};
int N; 
stack <int> st; 
inline int opidx(string s) {
    if(s == "push") return push;
    else if (s == "pop") return pop;
    else if (s == "size") return size;
    else if (s == "empty") return empty;
    else if (s == "top") return top;

    return -1;  
}
    
int main(){
    cin >> N ;
    while(N--) {
        string op; 
        int operand =0 ; 
        cin >>op ;
        switch(opidx(op)) {
            case push :
                cin >> operand;
                st.push(operand);
                break;
            case pop : 
                if(st.size()) {cout << -1 << endl;}
                else {cout << st.top() << endl;st.pop();}
                break;
            case size : 
                cout << st.size() << endl;
                break;
            case empty :
                cout << st.empty() << endl;
                break;
            case top :
                if(st.size()) cout << -1 << endl;
                else {cout << st.top() << endl;}
                break;
        }
    }

    
    return 0;
}