#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int N, M;
int map[50][50] = {0, };
vector<pair<int,int> > virusStart;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool visit[50][50] = {false, 0};

int MAP[10][50][50] = {0 ,};
int MAX;

void bfs(int x, int y, int (*a)[50]){
    queue<pair<int, int> > q;
    int cnt = 0;
    q.push(make_pair(y, x));
    visit[y][x] = true;
    a[y][x] = 0;

    while(!q.empty()){

        int qy = q.front().first;
        int qx = q.front().second;

        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if (nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1)
                continue;
            if (a[ny][nx] == -1)
                continue;

            if (visit[ny][nx] == false)
            {
                q.push(make_pair(ny, nx));
                visit[ny][nx] = true;
               
                a[ny][nx] = a[qy][qx]+1;
            }
        }
    }
}

//bfs로 해야함.
void dfs(int depth, int x, int y, int (*a)[50]){
    
    visit[y][x] = true;
    a[y][x] = depth;    


    for(int i = 0; i<4; i++){

        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx > N-1 || ny > N-1)
            continue;
        if(a[ny][nx] == -1)
            continue;

        if(visit[ny][nx] == true)
            continue;
        visit[ny][nx] = true;
        dfs(depth + 1, nx, ny, a);
    }

}


int main(){

    cin >> N >> M;

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j< N; j++){
    //         int a;
    //         cin >> a;
    //         if(a == 1)
    //         {
    //             map[i][j] = -1;
    //             continue;
    //         }
    //         map[i][j] = a;
    //         if(a == 2){
    //             virusStart.push_back(make_pair(i,j));
    //         }
    //     }
    // }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int a;
            cin >> a;
            if (a == 1)
            {
                MAP[0][i][j] = -1;
                continue;
            }
            MAP[0][i][j] = a;
            if (a == 2)
            {
                virusStart.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 1; i < virusStart.size(); i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                MAP[i][j][k] = MAP[0][j][k];
            }
        }
    }


    for(int i = 0; i<virusStart.size(); i++){
        bfs(virusStart[i].second,virusStart[i].first, MAP[i]);
        memset(visit, false, sizeof(visit));
    }

    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << MAP[1][i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}