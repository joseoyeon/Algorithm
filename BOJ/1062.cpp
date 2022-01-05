#include<iostream>
#include<vector>
using namespace std;

int Bigger(int a, int b) {if (a>b) return a; return b;}
int N, K,Answer;
int visited[26];
vector <string> str;

int CanReadNum()
{
    bool Read;
    int Cnt = 0;
    for (int i = 0; i < N; i++){
        Read = true;
        string tmp = str[i];
        for (int j = 0; j < tmp.length(); j++){
            if (visited[tmp[j] - 'a'] == 0){
                Read = false;
                break;
            }
        }
 
        if (Read == true){Cnt++;}
    }
    return Cnt;
}


void DFS(int Idx, int Cnt) {
    if (Cnt == K) {
        Answer = Bigger(Answer, CanReadNum());
        return ;
    }
    for(int i = Idx; i< 26; i++) {
        if (visited[i] == 1) continue;
        visited[i] = 1;

        DFS(i, Cnt +1);
        visited[i]  = 0;
    }
}

int main() {
    cin >> N >> K; 
    for (int i =0 ; i<N; i++) {
        string temp; 
        cin >> temp ; 
        str.push_back(temp); // 글자 받기 
    }
    // 일단 모든 단어가 anta 로 시작되고 tica 로 끝나니 a,t,n,c,i 는 무조건 배워야 한다. 
    if (K < 5) {cout << 0 << endl; exit(0);}

    visited['a'-'a'] = 1; 
    visited['t'-'a'] = 1; 
    visited['n'-'a'] = 1;
    visited['c'-'a'] = 1; 
    visited['i'-'a'] = 1;  
    K = K-5; 

    DFS(0,0);
    cout<<Answer<< endl;
    
    return 0;
}