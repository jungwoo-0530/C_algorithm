#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int N;
char map[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visit[101][101];

void bfs()
{
    
}

void dfs(int start_x, int start_y)
{
    visit[start_x][start_y] = 1;

    for(int i = 0; i<4; i++)
    {
        int nx = start_x + dx[i];
        int ny = start_y + dy[i];
        if(visit[nx][ny] == 1 || nx > N || ny > N || nx <= 0 || ny <= 0)
            continue;
        if(map[nx][ny] == map[start_x][start_y])
            dfs(nx, ny);
    }
}
void solve()
{
    int normal = 0;
    int unnormal= 0;
    memset(visit, 0, sizeof(visit));
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        for(int j =1; j <= N; j++)
        {
            char a;
            cin >> a;
            map[i][j] = a;
        }
    }
    for(int i =1; i<=N; i++)
    {
        for(int j = 1; j<=N; j++)
        {
            if(visit[i][j] == 0)
            {
                dfs(i,j);
                normal++;
            }
        }
    }
    memset(visit,0,sizeof(visit));
    for(int i = 1; i<=N; i++)
    {
        for(int j =1; j<=N; j++)
        {
            if(map[i][j] == 'G')map[i][j] = 'R';
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (visit[i][j] == 0)
            {
                dfs(i, j);
                unnormal++;
            }
        }
    }
    cout << normal << " " << unnormal;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}