#include <iostream>
#include<vector>
#include<cstdio>
#include<string.h>
using namespace std;

int node_num;
int parent[100001][18]; 
int depth[100001];
int max_height;
vector<int> adjection[100001];

void FindParentDFS(int par, int now, int dep){
  if(adjection[now].size() ==0)
    return;
  
  parent[now][0] = par;   //2^0 = 1, 1칸 위의 조상, 즉 부모 노드
  depth[now] = dep;

  for(int i=0; i<adjection[now].size() ; ++i){
    if(adjection[now][i] != par)
      FindParentDFS(now, adjection[now][i],dep+1);
  }
}

int FindLCA(int a, int b){

  if(depth[a] != depth[b]){ //depth[a] = depth[b]이도록 맞춰줌.
    if(depth[a] < depth[b]) //depth[a] != depth[b]라면 항상 a가 더 깊게
      swap(a, b);

    int dif = depth[a] - depth[b];
    for(int i =0; dif>0 ; ++i){
      if(dif%2 ==1) 
        a = parent[a][i];
      dif = dif>>1;
    }
  } 

  if(a != b){
    for( int k = max_height; k>=0 ; --k )
      if(parent[a][k] != 0 && parent[a][k] != parent[b][k]){
        a = parent[a][k];
        b = parent[b][k];
      }

    a=parent[a][0];
  }

  return a;
}

int main(){
  scanf("%d",&node_num);
  memset(adjection, 0, sizeof(adjection));
  memset(parent, 0, sizeof(parent));

  int a,b;
  for(int i=0; i<node_num-1 ; ++i){
    scanf("%d %d",&a, &b);
    adjection[a].push_back(b);
    adjection[b].push_back(a);
  }

  FindParentDFS(0, 1, 0);

  int temp = node_num, cnt=0;
  while(temp >1){
    temp = temp>>1;
    ++cnt;
  }
  max_height = cnt;

  for(int k = 1 ; k<=max_height ; ++k)
    for(int idx=2; idx<=node_num ; ++idx)
      if(parent[idx][k-1] != 0)
        parent[idx][k] = parent[parent[idx][k-1]][k-1];

  int pair_num;
  scanf("%d",&pair_num);
  while(pair_num--){
    scanf("%d %d",&a, &b);
    printf("%d\n",FindLCA(a, b) );
  }

  return 0;
}