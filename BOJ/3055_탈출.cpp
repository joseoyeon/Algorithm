#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int R,C, answer; 
vector <char> map[];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

queue<int,int> here;
queue<int,int> water;

int main() {
    cin >> R >> C;
    for (int i =0; i< R; i++) {
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {here.push((i,j))}
            if (map[i][j] == '*') {water.push((i,j))}
        }
    }

    //물이 있는 곳을 확인해 본다. 
    // 물을 확장 시킨다.
    // 고슴 도치가 가는 길을 확장 시킨다. 
    int x,y;
    x = here.front().first();
    y = here.front().first();
    
    // 고슴 도치가 가는 길을 확장시킬때, 물이 있는 곳과 닿으면 안된다. 

    //here 
    if (value = false) {cout << "KAKTUS" << endl; exit(0);}
    else {cout << answer << endl;}
    return 0;
}