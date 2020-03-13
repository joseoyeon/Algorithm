#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
 
struct balls {
    int depth;
    int rx, ry, bx, by;
};
int irx, iry, ibx, iby, hx, hy;
 
int n, m, ans = -1;
int map[10][10];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool visit[10][10][10][10];
char str[11];

void move(int& x, int& y, int d);

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i) {
        scanf("%s",str);
        for(int j=0; j<m; ++j) {
            switch(str[j]){
                case '.' :
                    map[i][j] = 0; break;
                case '#' :
                    map[i][j] = 1; break;
                case 'O' :
                    map[i][j] = 2; hx=i; hy=j; break;
                case 'R' :
                    irx =i; iry = j; break;
                case 'B' :
                    ibx =i; iby = j; break;
            }
        }
    } // input finish

    queue<balls> q;
    q.push({0,irx,iry,ibx,iby});
    visit[irx][iry][ibx][iby] = true;

while(!q.empty()){ // while queue empty
    balls cur = q.front(); q.pop();

    if (cur.depth >10){ break;}
    if(cur.rx == hx && cur.ry == hy) {ans = cur.depth; break;}

    for (int i=0; i<4; i++) {
        int rx = cur.rx,  ry = cur.ry;
        int bx = cur.bx,  by = cur.by;
        move(rx,ry,i); move(bx, by, i);// 같은 방향으로 동시에 돌리는 거

        if (map[bx][by] == 2) {continue;}

            if (rx == bx && ry == by) {
                switch (i) {
                case 0:
                    cur.rx < cur.bx ? rx-- : bx--; break;
                case 2:
                    cur.rx < cur.bx ? bx++ : rx++; break;
                case 1:
                    cur.ry < cur.by ? ry-- : by--; break;
                case 3:
                    cur.ry < cur.by ? by++ : ry++; break;
                }
            }

  if (!visit[rx][ry][bx][by]) {
                balls next = { cur.depth + 1,rx,ry,bx,by };
                q.push(next);
                visit[rx][ry][bx][by] = true;
            }
        }
    }

    printf("%d", ans);
    return 0;
}


void move(int& x, int& y, int d) {
    while (1) {
        x += dir[d][0]; y += dir[d][1];
        if (map[x][y] == 1) {
            x -= dir[d][0]; y -= dir[d][1];
            break;
        }
        else if (map[x][y] == 2)
            break;
    }
}
