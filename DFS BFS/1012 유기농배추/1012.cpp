#include<iostream>
#include<vector>
#include<string.h>

using namespace std;


int T;
int x_size, y_size, k;
int x, y;
int map[50][50];
int visit[50][50];
int ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void dfs(int x_, int y_)
{
    visit[x_][y_] = 1;

    for(int i = 0; i<4; i++)
    {
        int move_x = x_+dx[i];
        int move_y = y_+dy[i];
        if(move_x < 0 || move_y < 0 || move_x >= x_size || move_y >= y_size)continue;
            if(visit[move_x][move_y] == 0 && map[move_x][move_y] == 1 )
            {
                dfs(move_x, move_y);
            }
        
    }

}

void solve()
{

    for(int i = 0; i<k; i++)
    {
        cin >> x >> y;
        map[x][y] = 1;
    }
    

    for(int i = 0; i<x_size; i++)
    {
        for(int j = 0; j<y_size; j++)
        {
            if(map[i][j]==1 && visit[i][j]==0)
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    for(int i = 0; i<T; i++)
    {
        cin >> x_size >> y_size >> k;

        memset(visit, 0, sizeof(visit));
        memset(map, 0, sizeof(map));
        ans = 0;
        
        solve();
    }

    return 0;
}