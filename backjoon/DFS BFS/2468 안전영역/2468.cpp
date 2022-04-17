#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

int N;
int map[100][100];
int visit[100][100];
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};
int count_ = 0;
int ans = 0;
int max_value, min_value;
void dfs(int x_, int y_, int k)
{
    visit[x_][y_] = 1;

    for(int i = 0; i<4; i++)
    {
        int x_move = x_+x[i];
        int y_move = y_+y[i];
        if(x_move < 0 || y_move < 0 || x_move >= N || y_move >= N )continue;
        if(visit[x_move][y_move] == 0  && map[x_move][y_move] != 0 && k < map[x_move][y_move])
            dfs(x_move, y_move, k);
    }
    
}

void solve()
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i == 0 && j == 0)
            {
                max_value = map[0][0];
                min_value = map[0][0];
            }
            int a;
            cin >> a;
            map[i][j] = a;
            max_value = max(max_value, a);
            min_value = min(min_value, a);
        }
    }
    for(int k = min_value; k<max_value; k++)
    {
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if(visit[i][j] == 0 && k < map[i][j]) // 물에 잠기는 범위를 하나 더 추가.
                { 
                    dfs(i,j,k);
                    count_++;
                }
            }
        }
        ans = max(ans, count_);
        count_ = 0;
    }
    cout << ans;

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(map, 0, sizeof(map));
    memset(visit, 0, sizeof(visit));

    cin >> N;

    solve();

    return 0;
}