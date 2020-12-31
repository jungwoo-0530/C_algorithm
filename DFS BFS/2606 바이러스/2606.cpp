#include<iostream>
#include<vector>

using namespace std;
int N, con;

vector<vector<int>>adj;
int visit[101];
int a, b;
int ans = 0;

void dfs(int c)
{
    visit[c] = 1;
    ans++;

    for(int i = 0; i<adj[c].size(); i++)
    {
        if(visit[adj[c][i]] == 0)
            dfs(adj[c][i]);
        
    }
}

void solve()
{
    
    for(int i = 0; i<con; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout << ans-1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> con;
    //adj = vector< vector<int> >(N+1, vector<int>());
    adj.resize(N+1, vector<int>());
    solve();

    return 0;
}