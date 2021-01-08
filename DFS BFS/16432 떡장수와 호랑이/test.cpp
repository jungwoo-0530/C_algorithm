#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
//dfs로 N과 cnt가 같으면 성공
// 다르면 -1출력
// 첫번째 입력에 들어오는 것이 각각의 루트노드
// 두번째 입력부터 그의 자식들 트리.
// dfs.

int N;
int k;
bool chk = false;
int cnt = 0;
int visit[1001];
vector<int> map[10][10];//1번째부터
int root[9];//0번째부터
int root_num = 0;
void dfs(int start, int cnt_)
{
    visit[start] = 1;

    for (int i = 0; i < map[start].size(); i++)
    {
        if (visit[map[start][]])
            dfs(i + 1);
        dfs(i + 2);
    }
}

void solve()
{
    memset(visit, 0, sizeof(visit));

    cin >> N;

    for(int i = 0; i<N; i++)
    {
        cin >> k;

        if(i != 0)
        {
            for(int j = 0; j < map[i-1].size(); j++)
            {
                
            }
        }
    }
    //for(int j = 0; j < map[0].size(); j++)
    //    dfs(map[0][j]);
    dfs(map[0][0], 0);
    if (cnt != N)
        cout << "-1";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}