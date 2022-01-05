#include<iostream>
#include<vector>
#include <algorithm>

using namespace std; 

int main() {
int N ; // 3 이상 27이하의 자연수 카드수 
int T ; // test case 
int answer = 0;

cin >> T; 
for (int x =0; x < T; x++) {
    char card[28][4];
    vector <int> num[3]; 
    
    cin >> N; // 최대 카드가 만들어 질 수 있는 set은 N/3 개 
    for(int j =0 ; j< N; j++) {
        cin >> card[j]; 
        if (card[j][0] == '1' ) {num[0].push_back(j);}
        if (card[j][0] == '2')  {num[1].push_back(j);}
        if (card[j][0] == '3' ) {num[2].push_back(j);}
    }
    
vector<vector<int>> tmp; 
// 다른 속성 끼리 있는 거 모음 
    for (int i : num[0]) {
        for (int j : num[1]) {
             for(int k : num[2]) {
                if (card[i][1] == card[k][1] && card[j][1] != card[i][1]) {continue;}
                if (card[k][1] == card[j][1] && card[j][1] != card[i][1]) {continue;}
                if (card[i][1] == card[j][1] && card[k][1] != card[i][1]) {continue;}

                //shape  파악 
                if (card[i][2] == card[k][2] && card[j][2] != card[i][2]) { continue;}
                if (card[k][2] == card[j][2] && card[j][2] != card[i][2]) {continue;}
                if (card[i][2] == card[j][2] && card[k][2] != card[i][2]) { continue;}

                //shadow  파악 
                if (card[i][3] == card[k][3] && card[j][3] != card[i][3]) { continue;}
                if (card[k][3] == card[j][3] && card[j][3] != card[i][3]) {continue;}
                if (card[i][3] == card[j][3] && card[k][3] != card[i][3]) {continue;}
                
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
                //color 부터 파악 
                if (card[num[j][i]][1] == card[num[j][k]][1] && card[num[j][u]][1] != card[num[j][i]][1]) {continue;}
                if (card[num[j][k]][1] == card[num[j][u]][1] && card[num[j][u]][1] != card[num[j][i]][1]) {continue;}
                if (card[num[j][i]][1] == card[num[j][u]][1] && card[num[j][k]][1] != card[num[j][i]][1]) {continue;}

                //shape  파악 
                if (card[num[j][i]][2] == card[num[j][k]][2] && card[num[j][u]][2] != card[num[j][i]][2]) { continue;}
                if (card[num[j][k]][2] == card[num[j][u]][2] && card[num[j][u]][2] != card[num[j][i]][2]) {continue;}
                if (card[num[j][i]][2] == card[num[j][u]][2] && card[num[j][k]][2] != card[num[j][i]][2]) { continue;}

                //shadow  파악 
                if (card[num[j][i]][3] == card[num[j][k]][3] && card[num[j][u]][3] != card[num[j][i]][3]) { continue;}
                if (card[num[j][k]][3] == card[num[j][u]][3] && card[num[j][u]][3] != card[num[j][i]][3]) {continue;}
                if (card[num[j][i]][3] == card[num[j][u]][3] && card[num[j][k]][3] != card[num[j][i]][3]) {continue;}
                tmp.push_back({num[j][i],num[j][k],num[j][u]});
                }
            }
        } 
    }
}
    cout << endl;
    for (int i =0; i < tmp.size(); i++) {
        cout << tmp[i][0] <<  " " << tmp[i][1] << " " << tmp[i][2] << endl; 
    } 
    
    cout << endl; 
    cout << endl;
    vector<int> answer_link[tmp.size()]; // 서로소 집합 인덱스 
    int max_size = 0;
    int max_index = -1;
    for (int i =0; i<tmp.size(); i++) {
        for (int j=i+1; j< tmp.size(); j++){
           
            if (tmp[j][0] ==tmp[i][0] || tmp[j][1]==tmp[i][0] || tmp[j][2]==tmp[i][0]) {continue;}
            if (tmp[j][0] ==tmp[i][1] || tmp[j][1]==tmp[i][1] || tmp[j][2]==tmp[i][1]) {continue;}
            if (tmp[j][0] ==tmp[i][2] || tmp[j][1]==tmp[i][2] || tmp[j][2]==tmp[i][2]) {continue;}
            
            cout << i<<" " << tmp[i][0]  << " "  << tmp[i][1] <<  " " <<  tmp[i][2] << endl; 
            cout << i<<" " << tmp[j][0]  << " "  << tmp[j][1] <<  " " <<  tmp[j][2] << endl; 
            answer_link[i].push_back(j); // 같은거 없으면 넣는다.
        }
        if (max_size < answer_link[i].size()) {max_size = answer_link[i].size(); max_index = i; }
    }

    max_size =2; 

cout << " ************" << endl;
for (int j =0 ; j< tmp.size(); j++) {
    cout << j << endl;
    for (int i : answer_link[j]) {
        cout << i << " "; // count 할 수 있는 인덱스가 들어 있다. 
    }
    cout << endl;
}
    cout << endl;
        cout << "max index : "<< max_index << endl;
        for (int i : answer_link[max_index]) {
            cout << i << " "; // count 할 수 있는 인덱스가 들어 있다. 
            for (int next : answer_link[i]) {
                if(answer_link[max_index].end() != find(answer_link[max_index].begin(), answer_link[max_index].end(), next)){
                    cout << " next : " << next << " ";
                    max_size ++;
                }
            }
            cout << endl; 
            }
        cout << endl;

    int depth = 2; 
    int index = max_index;
    while(depth < 9){
        for (int i : answer_link[index]){
            for(int next : answer_link[i]) {
                if(answer_link[max_index].end() != find(answer_link[max_index].begin(), answer_link[max_index].end(), next)){
                    cout << " next : " << next << " ";
                    max_size ++;
                }
            }
        }
    }
    
    cout <<  "max : "<< max_size << endl; 
    if (max_size ==0 && tmp.size() == 1) {max_size = tmp.size();}
    cout <<"#"<< x+1 << ' ' << max_size << endl;
}
    return 0;
}