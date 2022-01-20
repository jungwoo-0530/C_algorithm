#include <iostream>
#include <queue>

using namespace std;

int N, M;

int dx[4] = {0, 1, 0, -1};//0인덱스는 북, 1인덱스는 동 ...
int dy[4] = {-1, 0, 1, 0};

int map[50][50] = {0, }; // 0빈칸, 1 벽
bool visit[50][50] = {false, };
int dir;//dir 0 북, 1 동, 2 남, 3 서 
//0(dir) -> 3, 1 -> 0, 2 -> 1, 3 -> 2
// 4방향 이므로 %4
// (현재 방향 + 3) % 4 = 다음방향.
int ans = 0;


void bfs(int x, int y)
{
    bool flag = false;

    queue<pair<int,int> >mQ;
    queue<int>dQ;

    mQ.push(make_pair(x, y));
    dQ.push(dir);

    while(!mQ.empty())
    {
        int cX = mQ.front().first;
        int cY = mQ.front().second;
        mQ.pop();
        int cD = dQ.front();
        dQ.pop();
        flag = false;


        if(map[cY][cX] == 0 && visit[cY][cX] == false)
        {
            ans++;
            visit[cY][cX] = true;
        }

        for(int i = 0; i<4; i++)//현재 방향, 위치에서 4방향을 다 검색. 새로운 방향(nD)에 맞춰서 새로운 위치가 일치해야함. nD가 북일 경우 서를 바라보고 서쪽으로이동 x-1 y
        {
            int nD = (cD + 3 - i) % 4;// 처음이 북일경우, 서3 -> 남2 -> 동1 -> 북0
            int nX = cX + dx[nD];//0북일 경우 서로 가야하니깐 x-1, y
            int nY = cY + dy[nD];

            if(nX >= M || nY >= N || nX < 0 || nY < 0)
                continue;
            if(map[nY][nX] == 1 || visit[nY][nX] == true)
                continue;

            mQ.push(make_pair(nX,nY));
            dQ.push(nD);
            flag = true;
            break;

        }


        if(flag == false)//4방향 청소할 곳이 없음.
        {
            int nX = cX + dx[(cD+2)%4];
            int nY = cY + dy[(cD+2)%4];
            if (map[nY][nX] == 1 || nX > M - 1 || nY > N - 1 || nX < 0 || nY < 0) //후진한 결과 벽이거나 범위를 넘어가면 끝냄.
                break;
            mQ.push(make_pair(nX, nY));
            dQ.push(cD);
        }
    }

}

int main(){


    cin >> N >> M;

    int startX, startY;
    cin >> startY >> startX >> dir;
    for(int i = 0; i < N; i++){
        for(int j = 0; j<M; j++)
        {
            cin >> map[i][j];
        }
    }

    bfs(startX, startY);

    cout << ans;

    return 0;
}