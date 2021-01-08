#include<iostream>
#include<queue>

using namespace std;


int T;
int before, after;
int visit[1000];

void bfs()
{
    visit[before] = 1;
    queue<int>q;
    q.push(before);

    while(!q.empty())
    {
        int a = q.front()
        q.pop();

        for(int i = 0; i)


    }
    
}

void solve()
{

    cin >> before >> after;
    
    bfs();

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}