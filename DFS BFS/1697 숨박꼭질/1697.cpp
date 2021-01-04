#include<iostream>
#include<queue>
#include<string.h>

using namespace std;
#define MAX 100000

int N, K;
int time_ = 0;
int visit[MAX];

void bfs(int position)
{
    queue<pair<int,int>>q;
    q.push(make_pair(position, time_));

    while(!q.empty())
    {
        int a  = q.front().first;
        int time_temp = q.front().second;
        q.pop();
        if(a == K)
        {
            cout << time_temp;
            return;
        }

        for(int i = 0; i<3; i++)
        {
            
          
            if(i == 0 && a+1 < MAX-1 && visit[a+1] == 0)
            {
                q.push(make_pair(a+1, time_temp+1));
                visit[a+1] = 1;
            }
            
            if (i == 1 && a-1 >= 0&& visit[a-1] == 0)
            {
                q.push(make_pair(a-1, time_temp+1));
                visit[a-1] = 1;
            }
            if (i == 2 && a*2 < MAX-1 && visit[a*2] == 0)
            {
                q.push(make_pair(a*2, time_temp+1));
                visit[a*2] = 1;
            }
            
        }

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