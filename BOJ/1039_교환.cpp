#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

int k;
queue<string> q; 

void swap(string& str, int left, int right){
    char tmp = str[left];
    str[left]= str[right];
    str[right] = tmp;
    return ;
}

int main() {
    string str;
    int K;
    cin >> str >> K; 
    q.push(str);

    for (int i =0; i<K; ++i) {
        set<string> s; 
        int qsize = q.size();
    
    for(int j =0; j<qsize; ++j){
        string item = q.front(); q.pop();
        if(s.count(item) != 0) continue; // 중복된 아이템은 탐색할 필요 없다. 
        s.insert(item);

        for(int left=0; left<item.size()-1; ++left){
            for(int right = left+1; right<item.size(); ++right) {
                if(!(left == 0 && item[right]=='0')) { // 맨 앞이 0 이 아닌거 
                    swap(item,left,right);
                    q.push(item);
                    swap(item,left,right); // 원래대로 돌려놓아야 한다. 
                }
            }
        }
    }
    }
    string ans = "0";
    while(!q.empty()) {
        ans=max(ans,q.front());
        q.pop();
    }
    if(ans == "0") cout << "-1" << endl;
    else cout << ans << endl; 
    return 0;
}