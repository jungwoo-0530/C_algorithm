#include<iostream>
#include<string.h>

using namespace std;

int map[51][51];
int Testcase;
int h, w;
bool visit[51][51];
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};


void dfs(int x, int y)
{
    visit[x][y] = true;

    for(int i=0; i<8; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx < 1 || ny < 1 || nx > h || ny > w)
            continue;
        if(!visit[nx][ny] && map[nx][ny] == 1)
            dfs(nx,ny);
    }

}


void solve()
{
    while(1)
    {
        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));
        int cnt = 0;

        cin >> w >> h;

        if (w == 0 && h == 0)
            break;

        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                int b;
                cin >> b;
                map[i][j] = b;
            
            }
        }
        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                if(!visit[i][j] && map[i][j] == 1)
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        
        cout << cnt << endl;

    }
    


}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);


    solve();


    return 0;
}