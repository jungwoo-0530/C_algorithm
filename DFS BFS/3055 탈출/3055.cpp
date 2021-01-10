#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;


int R, C;
char adj[50][50];
queue<pair<int, int>> water;
int ans[50][50];
bool visit[50][50];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int start_x, start_y;
int cnt;
//비어있는 곳 . , 물이 차있는 지역 *, 돌 X, 비버의 굴 D, 고슴도치 위치 S
//물(*)이 비어있는 칸(.)으로 매 분마다 확장, 다음 시간에 물이 찰 예정인 칸에는 고슴도치가 이동하지 못한다.
//물(*)과 고슴도치(S)는 돌(X)을 통과 X
//고슴도치(S)는 물로 이동할 수 없고 물(*)도 비버의 굴(D)로 이동할 수 없다.
//즉 물은 S, X, D


int bfs(int sx, int sy)
{
    visit[sx][sy] = true;

    queue<pair<int,int>>here;
    
    here.push(make_pair(sx,sy));
    
    while(!here.empty())
    {

        //물이동후에 고슴도치 이동(고슴도치 이동방향이 물이 찰 예정이면 안되므로 물을 먼저 채운다.)
        int water_loop = water.size();
        for(int j=0; j<water_loop;j++)
        {
            int w_x = water.front().first, w_y = water.front().second;
            water.pop();
                for (int i = 0; i < 4; i++) //물이동.
                {
                    int wx = w_x + dx[i], wy = w_y + dy[i];
                    if (wx > R - 1 || wy > C - 1 || wx < 0 || wy < 0)continue; //물의 이동이 맵 범위를 넘어서면 스킵.
                    if (adj[wx][wy] == '*' || adj[wx][wy] == 'D' || adj[wx][wy] == 'X' || adj[wx][wy] == 'S')
                        continue; //새로 이동하는 공간이 물이 이미 차있는 공간이거나 비버굴이거나 돌이면 스킵.
                        adj[wx][wy] = '*', water.push(make_pair(wx, wy)); //시작점이 물이고 새로운 위치가 비어있는 공간(.)이라면
                                                                          //맵에 물을 채우고 water 맵에 트루.
                }
        }
        int here_size = here.size();
        //cout << endl << "here size" << here_size << endl;

        for(int m=0; m<here_size;m++)
        {
            int x = here.front().first, y = here.front().second;
            here.pop();
            //cout << endl << "pop" << x << y << endl;
            for(int i=0; i<4; i++)//고슴도치이동.
            {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx > R - 1 || ny > C - 1 || nx < 0 || ny < 0)//새로운 고슴도치 이동이 맵을 넘어서면 스킵
                    continue;       
                if(adj[nx][ny] == '*' || adj[nx][ny] == 'X')continue;//고슴도치 새로운 이동이 물이거나 돌이면 스킵.
                if(ans[nx][ny] == -1)
                {
                    ans[nx][ny] = ans[x][y] + 1;
                    here.push(make_pair(nx,ny));
                    //cout << endl << nx << " " << ny << endl;
                    if(adj[nx][ny] == 'D')return ans[nx][ny];
                }
            }
        }
        // cout<< "------------------------" << endl;
        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j < 6; j++)
        //     {
        //         cout << adj[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for(int i=0; i<3; i++)
        // {
        //     for(int j=0; j<6; j++)
        //     {
        //         cout << ans[i][j];
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}


void solve()
{
    memset(ans, -1, sizeof(ans));
    cin >> R >> C;

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
        {
            char a; 
            cin >> a;
            adj[i][j] = a;
            if(a == 'S')
                start_x = i, start_y = j, ans[start_x][start_y] = 0;
            if(a == '*') water.push(make_pair(i,j));
        }
    int ans_ = bfs(start_x, start_y);

    if(!ans_)cout << "KAKTUS";
    else cout << ans_;

    // cout << endl;
    // for(int i=0; i<3; i++)
    // {
    //     for(int j=0; j<6; j++)
    //     {
    //         cout << ans[i][j];
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 6; j++)
    //     {
    //         cout << adj[i][j];
    //     }
    //     cout << endl;
    // }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}