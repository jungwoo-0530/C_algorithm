#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int Testcase;
int h, w;
vector<int>map[101];
queue<int>q;
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};
int point1[2], point2[2];
int count_ = 0;
char start[101][101];
// . : 빈공간 , $ : 죄수위치, * : 문위치

void bfs()
{
    for(int i = 1; i<=h, i++)
    {
        for(int j = 1; j<=w; j++)
        {
            if(map[0][j] == "#")
                start = j;
        }
    }

    visit[]
    
    while(!q.empty())
    {

    }
}

void solve()
{
    // cin >> Testcase;

    // for(int i = 0; i<Testcase; i++)
    // {

    // }
    cin >> h >> w;

    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            char a;
            cin >> a;
            map[i].push_back(a);

        }
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