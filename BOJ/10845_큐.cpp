#include<iostream>
#include<queue>
#include<string>
using namespace std;

int N; 
queue <int> q; 
    
int main(){
    cin >> N ;
    while(N--) {
        string op; 
        int operand =0 ; 
        cin >>op ;
        if(op == "push"){
            cin >> operand;
            q.push(operand);}
         if (op == "pop" ) {
            if(q.empty()) {cout << -1 << endl;}
            else {cout << q.front() << endl;q.pop();}}
        if (op == "size") {
            cout << q.size() << endl;}
        if (op == "empty") {
                cout << q.empty() << endl;}
        if (op == "front") 
            {if(q.empty()) cout << -1 << endl;
            else {cout << q.front() << endl;}}
        if (op == "back") {
            if(q.empty()) cout << -1 << endl;
            else {cout << q.back() << endl;}}
    }

    return 0;
}