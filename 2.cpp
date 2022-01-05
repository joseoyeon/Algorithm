#include<iostream>
#include<vector>
#include <algorithm>

using namespace std; 

int main() {
int N ; // 3 이상 27이하의 자연수 카드수 
int T ; // test case 
char card[28][4];
vector <int> color[3]; 
vector <int> num[3]; 
vector <int> shape[3];
vector <int> shadow[3];
int answer = 0;


int map[28][28]; 

cin >> T; 
for (int x =0; x < T; x++) {
    cin >> N; // 최대 카드가 만들어 질 수 있는 set은 N/3 개 
    for(int j =0 ; j< N; j++) {
        cin >> card[j]; 
        if (card[j][0] == '1' ) {num[0].push_back(j);}
        if (card[j][0] == '2')  {num[1].push_back(j);}
        if (card[j][0] == '3' ) {num[2].push_back(j);}
        
        if (card[j][1] == 'R')  {color[0].push_back(j);}
        if (card[j][1] == 'G')  {color[1].push_back(j);}
        if (card[j][1] == 'P')  {color[2].push_back(j);}
        
        if (card[j][2] == 'E')  {shape[0].push_back(j);}
        if (card[j][2] == 'D')  {shape[1].push_back(j);}
        if (card[j][2] == 'T')  {shape[2].push_back(j);}
        
        if (card[j][3] == 'F')  {shadow[0].push_back(j);}
        if (card[j][3] == 'S')  {shadow[1].push_back(j);}
        if (card[j][3] == 'W')  {shadow[2].push_back(j);}
    }
    
    /////////
    cout << N << endl;
    for(int j =0 ; j< N; j++) {cout << card[j][0] << ' ';}
    cout << endl;
    
    
    for(int j =0 ; j< 3; j++) {
        cout << j << endl;
        for (int i : num[j]) cout << i << " ";
        cout << endl;
    }
    cout << endl;
    ////////////

vector<vector<int>> tmp; 
// 다른 속성 끼리 있는 거 모음 
    for (int i : num[0]) {
        for (int j : num[1]) {
             for(int k : num[2]) {
                tmp.push_back({i,k,j});
            }
        }
    } 
// 같은 속성 끼리 있는 거 모음     
for (int j =0 ; j < 3; j++){
    if (num[j].size() > 2) {
        for (int i =0; i< num[j].size(); i++) {         
            for (int k = i+1; k< num[j].size(); k++) {        
                for (int u = k+1; u< num[j].size(); u++) {
                    tmp.push_back({num[j][i],num[j][k],num[j][u]});
                }
            }
        } 
    }
}

///////////////////////////////////////////////
cout << "************" << endl;
    for (int i =0; i < tmp.size(); i++) {
        cout << tmp[i][0] <<  " " << tmp[i][1] << " " << tmp[i][2] << endl; 
    } 
cout << "************" << endl;
//////////////////////////////////////////////
    
// 후보 순서대로 같은 건지 다른 건지 파악 
int find_V[3] = {-1,}; 
    for (int i =0; i < tmp.size(); i++) {
        cout << endl; 
        cout << tmp.size() << endl;
    //color 부터 파악 
        for (int k =0; k< 3; k++) {find_V[k] = card[tmp[i][k]][1];} // j번에서 찾는다. 

        for (int t =0 ; t < 3; t ++) { cout << tmp[i][t] << " " << find_V[t] << ' ';}
        // find_V 의 값이 다 같거나 다 다르면 ok 아이면 tmp 에서 삭제한다. 
        if (find_V[0] == find_V[1] && find_V[2] != find_V[0]) {tmp.erase(tmp.begin() + i); i--; }
        if (find_V[2] == find_V[1] && find_V[2] != find_V[0]) {tmp.erase(tmp.begin() + i);i--; }
        if (find_V[0] == find_V[2] && find_V[1] != find_V[0]) {tmp.erase(tmp.begin() + i);i--; }
    }
///////////////////////////////////////////////
cout << "****color********" << endl;
    for(int j =0 ; j< 3; j++) {
        cout << j << endl;
        for (int i : color[j]) cout << i << " ";
        cout << endl;
    }
    cout << endl;

    for (int i =0; i < tmp.size(); i++) {
        cout << tmp[i][0] <<  " " << tmp[i][1] << " " << tmp[i][2] << endl; 
    } 
cout << "************" << endl;
//////////////////////////////////////////////
    for (int i =0; i < tmp.size(); i++) {    
    //shape  파악 
        for (int k =0; k< 3; k++) {find_V[k] = card[tmp[i][k]][2];} // j번에서 찾는다. 
                // find_V 의 값이 다 같거나 다 다르면 ok 아이면 tmp 에서 삭제한다. 
        if (find_V[0] == find_V[1] && find_V[2] != find_V[0]) {tmp.erase(tmp.begin() + i);i--; }
        if (find_V[2] == find_V[1] && find_V[2] != find_V[0]) {tmp.erase(tmp.begin() + i);i--; }
        if (find_V[0] == find_V[2] && find_V[1] != find_V[0]) {tmp.erase(tmp.begin() + i);i--; }
        }

///////////////////////////////////////////////
cout << "****shape********" << endl;
    for(int j =0 ; j< 3; j++) {
        cout << j << endl;
        for (int i : shape[j]) cout << i << " ";
        cout << endl;
    }
    cout << endl;

    for (int i =0; i < tmp.size(); i++) { cout << tmp[i][0] <<  " " << tmp[i][1] << " " << tmp[i][2] << endl;}  
cout << "************" << endl;
//////////////////////////////////////////////
    for (int i =0; i < tmp.size(); i++) {
        //shadow  파악 
        for (int k =0; k< 3; k++) {find_V[k] = card[tmp[i][k]][3];} // j번에서 찾는다. 
                // find_V 의 값이 다 같거나 다 다르면 ok 아이면 tmp 에서 삭제한다. 
        if (find_V[0] == find_V[1] && find_V[2] != find_V[0]) {tmp.erase(tmp.begin() + i);i--; }
        if (find_V[2] == find_V[1] && find_V[2] != find_V[0]) {tmp.erase(tmp.begin() + i);i--; }
        if (find_V[0] == find_V[2] && find_V[1] != find_V[0]) {tmp.erase(tmp.begin() + i);i--;}
    }

    ///////////////////////////////////////////////
cout << "****shadow********" << endl;
    for(int j =0 ; j< 3; j++) {
        cout << j << endl;
        for (int i : shadow[j]) cout << i << " ";
        cout << endl;
    }
    cout << endl;
    for (int i =0; i < tmp.size(); i++) {
        cout << tmp[i][0] <<  " " << tmp[i][1] << " " << tmp[i][2] << endl; 
    } 
cout << "************" << endl;
//////////////////////////////////////////////

    cout <<"#"<< x+1 << ' ' << tmp.size() << endl;
}
    return 0;
}