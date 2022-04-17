#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int Testcase; 
int I;
int start_x, start_y;
int end_x, end_y;
int visit[300][300];
int map[300][300];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
void bfs()
{
    if(start_x == end_x && start_y == end_y)
        cout << 0;
    visit[start_x][start_y] = 1;
    queue<pair<int,int>>q;
    q.push(make_pair(start_x, start_y));  
    while(!q.empty())
    {
        int s_x = q.front().first;
        int s_y = q.front().second;
        q.pop();
        for(int i = 0; i<8; i++)
        {
            int x = s_x + dx[i];
            int y = s_y + dy[i];

            if(visit[x][y] == 1)continue;
            if(x < 0 || y < 0 || x >= I || y >= I)continue;
            
            visit[x][y]=1;
            map[x][y] = map[s_x][s_y] + 1;
            q.push(make_pair(x, y));
            if(x == end_x && y == end_y)
                cout << map[x][y];
        }
    }
}

void solve()
{

    cin >> Testcase;
    for(int i=0; i<Testcase; i++)
    {
        memset(visit,0, sizeof(visit));
        memset(map, 0, sizeof(map));
        cin >> I;

        cin >> start_x >> start_y;
        cin >> end_x >> end_y;

        bfs();
        cout << "\n";
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