#include<iostream>
#include<vector>
#include<string.h>


using namespace std;

int R, C;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char map[20][20];
int visit[26];
int ans;

int bigger(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

void dfs(int sx = 0, int sy = 0, int cnt = 1)
{   
    ans = bigger(ans, cnt);
    visit[map[sx][sy]-'A'] = 1;

    for(int i = 0; i < 4; i++)
    {
        int x = sx + dy[i];
        int y = sy + dx[i];
        if(x < 0 || x > R-1 || y < 0 || y > C-1)continue;
        
        if(visit[map[x][y] - 'A'] == 0)
        {
            dfs(x, y, cnt+1);
            visit[map[x][y] - 'A'] = 0;
        }

    }
}


void solve()
{
    cin >> R >> C;
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i < R; i++)
        for(int j = 0; j<C; j++)
            cin >> map[i][j];

    dfs();

    cout << ans;


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}