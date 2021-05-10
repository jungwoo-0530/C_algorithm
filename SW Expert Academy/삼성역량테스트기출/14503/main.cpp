#include<iostream>
#define MAX 51
using namespace std;


int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N, M;
int r, c, d;
int map[MAX][MAX];
//바라보고 있는 방향 0 북쪽, 1 동쪽, 2 남, 3 서
//0이면 dx[]
//0에서 왼쪽방향으로 이동 [0][-1] 3
//3에서 왼쪽방향으로 이동 [-1][0] 2
//2에서 왼쪽방향으로 이동 [0][1] 1
//1에서 왼쪽방향으로 이동 [1][0] 0 
void solve()
{
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cin >> map[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}