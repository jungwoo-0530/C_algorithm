#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;

int Testcase;
int h, w;//h : 행의 갯수, w : 열의 갯수
char map[102][102];//
queue<pair<int,int>>start;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int door_num[102][102][3];//각 위치 별 문의 갯수를 저장.(최소거리를 구하는 것이였다면 dist거리를 말한다.)
// . : 빈공간 , $ : 죄수위치, # : 문위치, * : 벽
// 2차원배열필요 map
// 지나온길 기록(visit2차원배열.)
// 출발점이 한개가 아니라 여러개 이므로 출발점별로 $(target)으로 가는 값들을 구해서 최소값(min)을 구한다.
// 여러개의 출발점을 넣을 벡터를 큐에 넣기. -> 큐에서 한개씩 빼서 그것을 출발점으로 $위치에 도달.
void bfs()
{

    start.push(make_pair(0, 0)); //상근이 출발점.

    for(int i = 0; i<3; i++)
    {

        queue<pair<int, int>>q;

        int start_x = start.front().first;//x좌표
        int start_y = start.front().second;//y좌표
        start.pop();
        q.push(make_pair(start_x, start_y));
        door_num[start_x][start_y][i] = 0;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int j = 0; j < 4; j++)
            {   
                int nx = x+dx[j];
                int ny = y+dy[j];

                if(nx > h+1 || ny > w+1 || nx < 0 || ny < 0)continue;
                if(map[nx][ny] == '*')continue;
                if(door_num[nx][ny][i] >= 0)continue;//door_num배열이 0초과라는 것은 방문했다는 것.
                if (map[nx][ny] == '.')         //빈공간이면 새로운좌표 = 전좌표
                {
                    door_num[nx][ny][i] = door_num[x][y][i];
                    q.push(make_pair(nx, ny));
                }
                else if(map[nx][ny] == '#')//문이면 새로운좌표 전좌표에 +1.
                {
                    door_num[nx][ny][i] = door_num[x][y][i] + 1;
                    q.push(make_pair(nx,ny));
                }

            }
        }
        
    }
}

void solve()
{
    cin >> Testcase;

    for(int i = 0; i<Testcase; i++)
    {
    cin >> h >> w;
    memset(door_num, -1 , sizeof(door_num));
    for(int i = 0; i <= h+1; i++)
    {
        for(int j = 0; j <= w+1; j++)
        {
            if(i == 0 || j == 0 || i == h+1 || j == w+1)
            {
                map[i][j] = '.';
            }
            else{
                char a;
                cin >> a;
                map[i][j] = a;
            }
            
            if(map[i][j] == '$')//범죄자 위치, 즉, 출발점.
            {
                map[i][j] = '.';
                start.push(make_pair(i,j));
            }

        }
    }

    bfs();

    int ans = 1e9;


    for(int i = 0; i <= h+1; i++)
    {
        for(int j = 0; j <= w+1; j++)
        {
            if(map[i][j] == '*')continue;
            int temp = door_num[i][j][0] + door_num[i][j][1] + door_num[i][j][2];
            if(map[i][j] == '#')
                temp -= 2;
            if(ans > temp)
                ans = temp;
        }
    }
    cout<< endl;
    cout << ans;

    //출발점 start 큐에 넣기
    
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}