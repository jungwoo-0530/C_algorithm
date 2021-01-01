#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int Testcase;
int h, w;
vector<int>map[101];
queue<int>q;
queue<pair<int,int>> start;
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};
int point1[2], point2[2];
int count_ = 0;
// . : 빈공간 , $ : 죄수위치, * : 문위치
// 2차원배열필요 map
// 지나온길 기록(visit2차원배열.)
// 출발점이 한개가 아니라 여러개 이므로 출발점별로 $(target)으로 가는 값들을 구해서 최소값(min)을 구한다.
// 여러개의 출발점을 넣을 벡터를 큐에 넣기. -> 큐에서 한개씩 빼서 그것을 출발점으로 $위치에 도달.
void bfs()
{
    
    int start_x = start.front().first;
    int start_y = start.front().second;
s
    

    for(int i = 0; i<start.size(); i++)
    {
        int start_x = start.front().first;
        int start_y = start.front().second;

        while()


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
            if((i == 1 || j == 1 || i == h || j == w) && a == '#' )// map의 테두리 부분은 출발점인 start 큐에 #을 넣는다.
            {
                start.push(make_pair(i,j));시작점넣기.
            }
        }
    }
    //출발점 start 큐에 넣기
    

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}