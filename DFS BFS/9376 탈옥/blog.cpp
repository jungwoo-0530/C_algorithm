#include <cstdio>
#include <cstring>
#include <deque>
#include<queue>
using namespace std;

struct prison
{
    int x, y;
};

int h, w;
char a[102][102];
int dist[102][102][3];
//deque<prison> dq;
queue<pair<int,int>>dq;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void bfs()
{
    //dq.push_back({0, 0});
    dq.push(make_pair(0,0));
    for (int k = 0; k < 3; k++)
    {
        int sx = dq.front().first, sy = dq.front().second;
        dq.pop();
        //deque<prison> q;
        queue<pair<int,int>> q;
        q.push(make_pair(sx, sy));
        dist[sx][sy][k] = 0;
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1)
                    continue;
                if (dist[nx][ny][k] >= 0 || a[nx][ny] == '*')
                    continue;
                if (a[nx][ny] == '.')
                {
                    
                    dist[nx][ny][k] = dist[x][y][k];
                    q.push(make_pair(nx, ny));
                }
                else if (a[nx][ny] == '#')
                {
                    dist[nx][ny][k] = dist[x][y][k] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(dist, -1, sizeof(dist));
        scanf("%d %d", &h, &w);
        for (int i = 0; i < h + 2; i++)
        {
            for (int j = 0; j < w + 2; j++)
            {
                if (i == 0 || i == h + 1 || j == 0 || j == w + 1)
                    a[i][j] = '.';
                else
                    scanf(" %1c", &a[i][j]);
                if (a[i][j] == '$')
                {
                    a[i][j] = '.';
                    dq.push(make_pair(i, j));
                }
            }
        }
        bfs();
        int ans = 1e9;
        for (int i = 0; i < h + 2; i++)
        {
            for (int j = 0; j < w + 2; j++)
            {
                if (a[i][j] == '*')
                    continue;
                int k = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];
                if (a[i][j] == '#')
                    k -= 2;
                if (ans > k)
                    ans = k;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
