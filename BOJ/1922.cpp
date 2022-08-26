#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std; 


    int parent[1000];
class Node{
    public :
    int a; 
    int b;
    int c; 
    Node(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    bool operator<(Node& node){
        return this->c < node.c;
    }
};

int findparent (int a){
    if(parent[a] == a) {return a;}
    return parent[a] = findparent(parent[a]);
}

void unionparent(int a, int b){
    int A = findparent(a);
    int B = findparent(b);
    if (A > B) {
        parent[A] = B;
    } else {
        parent[B] = A;
    }
}

bool sameparent(int a, int b){
    return findparent(a) != findparent(b);
}
int main() {
    int N,M;
    vector<Node> node; 
    scanf("%d",&N);
    scanf("%d",&M);
    int a, b, c ;
    
    // parent 
    for(int i=0; i<N; i++){
        parent[i] = i;
    }
    for(int i=0; i< M; i++){
        scanf("%d %d %d",&a, &b, &c);
        node.push_back(Node(a,b,c));
    }
    sort(node.begin(), node.end());
    int solve = 0;
    for(int n =0; n< node.size(); n++){
        if (sameparent(node[n].a, node[n].b)){
            //일단 노드를 합친다. 
            unionparent(node[n].a, node[n].b);
            solve += node[n].c;
        }
    }
    printf("%d", solve);
    return 0;
}