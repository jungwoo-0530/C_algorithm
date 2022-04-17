#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
#define MAX 100001

int N, K;
int time_ = 0;
int visit[MAX];

void bfs(int start)
{
    visit[start] = true;

    queue<pair<int, int>>a;

    while(!a.empty())
    {
        a.push();
        a.push();
        a.push();
        int posit;
        posit = a.front();
        a.pop();

    }

}

void solve()
{
    cin >> N >> K;
    memset(visit, 0, sizeof(visit));

    bfs(N);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}