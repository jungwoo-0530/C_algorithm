#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
//https://hibee.tistory.com/201
/*
종료 조건
1. 파란색이 빠진다. -1 (빨강과 파랑이 같이 들어가면 실패)-> 빨강들어가도 파랑이 끝날때까지 대기.
2. 10번이상 회전 -1
3. 빨간색이 빠져나감 성공
문제 흐름
1.빨간 구슬, 파란 구슬, 구멍의 좌표를 따로 보관한다
2. dfs 함수의 매개변수로 빨간구슬의 좌표 , 파란구슬의 좌표 , 카운트값 을 전달한다
3. 불가능한 경우와 답을 찾은 경우를 조건문으로 처리한다
4. 위의 경우가 아니라면 보드를 상 하 좌 우 로 움직인다
5. 만약 두 구슬이 구멍이 아닌 곳에서 겹쳤다면 기존 위치의 우선순위를 이용해 재조정한다
6. 이동한 위치가 아직 방문하지 않은 위치라면 방문 처리 후, dfs 탐색을 이어나간다
--------------------------------------
구현
1.함수로 빨간 구슬 이동, 파란 구슬 이동(4방향)-
2.두 구슬이 겹친다(1. 구멍이 아니라면 하나의 구슬 좌표를 재조정, 2.구멍이면 끝.)
*/

int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};
int N, M;
char map[11][11];
bool visit[11][11][11][11] = {false, };
int Rstart_x, Rstart_y;
int Bstart_x, Bstart_y;
int End_x, End_y;
int answer;


//빨간공 파란공 포인터로 좌표를 받아서 한 방향으로 최종 이동한 좌표 반환.
void move(int &Rx, int &Ry, int &Bx, int &By, int dir)
{
    queue<pair<int,int>>Rq;
    queue<pair<int,int>>Bq;

    Rq.push(make_pair(Rx, Ry));
    while(!Rq.empty())
    {
        int move_x = Rq.front().first;
        int move_y = Rq.front().second;
        Rq.pop();
        Rx = move_x + x[dir];
        Ry = move_y + y[dir];

        if (map[Rx][Ry] == 'O')//이동한곳이 구멍이면 이동한 곳 그대로 반환.
            break;
        
        else if (map[Rx][Ry] == '#')//이동한 곳이 벽이면 한칸 이동하기 전으로 이동해서 반환.
        {
            Rx = move_x;
            Ry = move_y;
            break;
        }

        Rq.push(make_pair(Rx,Ry));
    }
    if (!Rq.empty())
    {
        queue<pair<int,int>> empty;
        swap(Rq, empty);
    }

    Bq.push(make_pair(Bx, By));
    while (!Bq.empty())
    {
        int move_x = Bq.front().first;
        int move_y = Bq.front().second;
        Bq.pop();
        Bx = move_x + x[dir];
        By = move_y + y[dir];

        if (map[Bx][By] == 'O') //이동한곳이 구멍이면 이동한 곳 그대로 반환.
            break;

        else if (map[Bx][By] == '#') //이동한 곳이 벽이면 한칸 이동하기 전으로 이동해서 반환.
        {
            Bx = move_x;
            By = move_y;
            break;
        }

        Bq.push(make_pair(Bx, By));
    }
    if (!Bq.empty())
    {
        queue<pair<int, int>> empty;
        swap(Bq, empty);
    }
}




void dfs(int Rx, int Ry, int Bx, int By,int depth)
{
    if(depth >= answer)
        return;
    //빨간공이 구멍에 들어가고 파란공 x
    if (depth > 10)
        return;

    //빨간공, 파란공 둘다 들어갈경우
    if (Rx == End_x && Ry == End_y && Bx == End_x && By == End_y)
        return;
    //빨간공이 구멍에 안들어가고 파란공 o
    if(Rx != End_x && Ry != End_y && Bx == End_x && By == End_y)
        return;

    if (Rx == End_x && Ry == End_y && Bx != End_x && By != End_y)
    {
        answer = min(depth, answer);
        return;
    }
    for(int i =0; i<4; i++)
    {
        int Rnx = Rx; int Rny = Ry;
        int Bnx = Bx; int Bny = By;
        move(Rnx, Rny, Bnx, Bny, i);

        if (Rnx == Bnx && Rny == Bny)
        {
            // 구멍에서 겹친 경우 제외
            if (Rnx == End_x && Rny == End_y)
                continue;

            switch (i)
            {
            // 빨간 구슬이 더 오른쪽에 있었다면
            case 0:
                Ry - By > 0 ? Bny-- : Rny--;
                break;
            // 빨간 구슬이 더 왼쪽에 있었다면
            case 1:
                Ry - By < 0 ? Bny++ : Rny++;
                break;
            // 빨간 구슬이 더 아래쪽 있었다면
            case 2:
                Rx - Bx > 0 ? Bnx-- : Rnx--;
                break;
            // 빨간 구슬이 더 오른쪽에 있었다면
            case 3:
                Rx - Bx < 0 ? Bnx++ : Rnx++;
                break;
            default:
                break;
            }
        }
        if (!visit[Rnx][Rny][Bnx][Bny])
        {
            visit[Rnx][Rny][Bnx][Bny] = true;
            dfs(Rnx, Rny, Bnx, Bny, depth + 1);
            visit[Rnx][Rny][Bnx][Bny] = false;
        }
    }

}

void solve()
{
    cin >> N >> M;
    for(int i = 0; i<N; i++)//y좌표
    {
        for(int j = 0; j<M; j++)//x좌표
        {
            cin >> map[i][j];
            if(map[i][j] == 'O')
                End_x = i, End_y = j;
            else if(map[i][j] == 'R')
                Rstart_x = i, Rstart_y = j;
            else if(map[i][j] == 'B')
                Bstart_x = i, Bstart_y = j;
        }
    }
    answer = 500;
    visit[Rstart_x][Rstart_y][Bstart_x][Bstart_y] = true;
    dfs(Rstart_x, Rstart_y, Bstart_x, Bstart_y, 0);
    if(answer == 500)
        cout << -1;
    else
        cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}