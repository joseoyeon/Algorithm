#include <bits/stdc++.h>
#include <queue>
#include <algorithm>
using namespace std;

struct BOLL
{
    int ry, rx, by, bx, count;
};

BOLL start;
char maps[10][11];

int bfs()
{
    const int dy[] = {-1, 1, 0, 0};
    const int dx[] = {0, 0, -1, 1};

    int visited[10][10][10][10] = {0,};
    queue<BOLL> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;
    int ret = -1;
    while (!q.empty())
    {
        BOLL cur = q.front();
        q.pop();
        if (cur.count > 10) break;
        if (maps[cur.ry][cur.rx] == 'O' && maps[cur.by][cur.bx] != 'O')
        {
            ret = cur.count;
            break;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int next_ry = cur.ry;
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;
            while (1)
            {
                if (maps[next_ry][next_rx] != 'O' && maps[next_ry][next_rx] != '#')
                {
                    next_ry += dy[dir], next_rx += dx[dir];
                }
                else
                {
                    if (maps[next_ry][next_rx] == '#')
                    {
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    break;
                }
            }

            while (1)
            {
                if (maps[next_by][next_bx] != 'O' && maps[next_by][next_bx] != '#')
                {
                    next_by += dy[dir], next_bx += dx[dir];
                }
                else
                {
                    if (maps[next_by][next_bx] == '#')
                    {
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                    break;
                }
            }

            if (next_ry == next_by && next_rx == next_bx)
            {
                if (maps[next_ry][next_rx] != 'O')
                {
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
                    if (red_dist > blue_dist)
                    {
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    else
                    {
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                }
            }
            if (visited[next_ry][next_rx][next_by][next_bx] == 0)
            {
                visited[next_ry][next_rx][next_by][next_bx] = 1;
                BOLL next;
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int N, M;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", maps[i]);
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (maps[y][x] == 'R')
            {
                start.ry = y, start.rx = x;
            }
            if (maps[y][x] == 'B')
            {
                start.by = y, start.bx = x;
            }
        }
    }

    start.count = 0;

    int ret = bfs();
    printf("%d\n", ret);
    return 0;
}