#include<iostream>
#include<vector>
#include<string.h>
#include<queue>

using namespace std;

int N;
int m;
int x, y;
int target1, target2;
vector<int>rel[101];
queue<pair<int,int>> q;//bfs
int visit[101];
int ans = 0;
int chk = 0;//dfs
//촌수: 트리의 최소거리. bfs
int bfs(int a)
{
    q.push(make_pair(a, 0));
    visit[a] = 1;
    while(!q.empty())
    {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        for(int i = 0; i < rel[node].size(); i++)
        {
            if(visit[rel[node][i]] == 0)
            {
                visit[rel[node][i]] = 1;
                q.push(make_pair(rel[node][i], dist+1));
                if(rel[node][i] == target2)
                    return dist+1;
            }
        }
    }
    return -1;
}
void dfs(int a, int dist)
{
    visit[a] = 1;
    if(a == target2)
    {
        cout << dist;
        chk = 1;
    }
    for(int i = 0; i < rel[a].size(); i++)
    {   
        if(visit[rel[a][i]] == 0)
        {
            visit[rel[a][i]] = 1;
            dfs(rel[a][i], dist+1);
            
        }
        
    }
    
}

void solve()
{
    cin >> N;
    cin >> target1 >> target2;
    cin >> m;

    for(int i = 1; i<=m; i++)
    {
        cin >> x >> y;
        rel[x].push_back(y);
        rel[y].push_back(x);
    }
    //cout << bfs(target1);
    dfs(target1, 0);
    if(!chk)
        cout << "-1";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(visit, 0, sizeof(visit));

    solve();

    return 0;
}