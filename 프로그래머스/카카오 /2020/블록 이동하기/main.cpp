#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>

using namespace std;
//오른쪽, 아래로이동 가능
// 90도 회전가능.

// vector

// x,y를 기준으로 방향을 저장해서 로봇의 다른 한쪽 좌표를 저장(xx,yy)
// [x][y][방향] = 시간
//(x,y)좌표에 방향값을 향하여 xx,yy좌표가 있음.

bool visit[100][100][4] = {
    false,
};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ndx[4] = {-1, 1, 1, -1};
int ndy[4] = {1, 1, -1, -1};

struct Robot
{

    int x = 0;
    int y = 0;
    int dir = 0; // 0:북 1:서 2:남 3:동
    int time = 0;

    Robot(int a, int b, int c, int d)
    {
        x = a;
        y = b;
        dir = c;
        time = d;
    }
};

bool check(int x, int y, int xx, int yy, int n)
{

    if (x < 0 || y < 0 || x >= n || y >= n)
        return false;
    if (xx < 0 || yy < 0 || xx >= n || yy >= n)
        return false;

    return true;
}

int solution(vector<vector<int>> board)
{

    int answer = 0;

    queue<Robot> q;
    q.push(Robot(0, 0, 0, 0));
    int n = board.size();
    int destX = n - 1;
    int destY = n - 1;
    visit[0][0][0] = true;

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        int time = q.front().time;
        q.pop();

        //다른 쪽 좌표
        int xx = x + dx[dir];
        int yy = y + dy[dir];

        //로봇 한칸 이라도 도착한다면.
        if ((x == destX && y == destY) || (xx == destX && yy == destY))
            return time;

        int nx, ny, nxx, nyy;
        //네방향으로 이동.
        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            nxx = xx + dx[i];
            nyy = yy + dy[i];

            //네방향으로 이동하는데 체크해서 컨티뉴.
            if (!check(nx, ny, nxx, nyy, n))
                continue;
            if (visit[nx][ny][dir] == true)
                continue;
            if (board[nx][ny] == 1 || board[nxx][nyy] == 1)
                continue;
            ;

            visit[nx][ny][dir] = true;
            q.push(Robot(nx, ny, dir, time + 1));
        }

        ///회전 두축을 중심으로 회전 2가지
        ///또한 왼쪽 오른쪽으로 회전 2가지
        /// 4가지.
        //왼쪽먼저.
        // x,y축 기준. xx,yy가 움직임.
        // i가 0일때 왼쪽.
        for (int i = 0; i < 2; i++)
        {

            int tempDir[2] = {(dir + 1) % 4, (dir + 3) % 4};

            int nDir = tempDir[i];

            nxx = x + dx[nDir];
            nyy = y + dy[nDir];

            //회전하면서 지나가는 좌표
            int rx, ry;
            //반시계방향
            if (i == 0)
            {
                rx = x + ndx[nDir];
                ry = y + ndy[nDir];
            }
            else
            {
                rx = x + ndx[dir];
                ry = y + ndy[dir];
            }

            if (!check(rx, ry, nxx, nyy, n))
                continue;
            if (visit[x][y][nDir])
                continue;
            if (board[rx][ry] == 1 || board[nxx][nyy] == 1)
                continue;
            ;

            visit[x][y][nDir] = true;
            q.push(Robot(x, y, nDir, time + 1));
        }

        // xx,yy,축으로
        //축변경으로 dir 변경
        dir = (dir + 2) % 4;
        for (int i = 0; i < 2; i++)
        {
            int tempDir[2] = {(dir + 1) % 4, (dir + 3) % 4};

            int nDir = tempDir[i];

            nx = xx + dx[nDir];
            ny = yy + dy[nDir];

            //회전하면서 지나가는 좌표
            int rx, ry;
            if (i == 0)
            {
                rx = xx + ndx[nDir];
                ry = yy + ndy[nDir];
            }
            else
            {
                rx = xx + ndx[dir];
                ry = yy + ndy[dir];
            }

            if (!check(rx, ry, nx, ny, n))
                continue;
            if (board[rx][ry] == 1 || board[nx][ny] == 1)
                continue;

            nDir = (nDir + 2) % 4;
            if (visit[nx][ny][nDir])
                continue;
            visit[nx][ny][nDir] = true;
            q.push(Robot(nx, ny, nDir, time + 1));
        }
    }

    return answer;
}
