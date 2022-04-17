#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int N;
vector<int>tree[100001];
int visit[100001];
int parent[100001];

void dfs(int a)
{
    visit[a] = 1;

    for(int i = 0; i<tree[a].size(); i++)
    {
        if(visit[tree[a][i]] == 0)
        {
            parent[tree[a][i]] = a;
            dfs(tree[a][i]);
        }
    }
}

void solve()
{
    cin >> N;
    memset(visit, 0, sizeof(visit));
    int parent_, child;
    for(int i = 0; i<N-1; i++)
    {
        cin >> parent_ >> child;
        tree[parent_].push_back(child);
        tree[child].push_back(parent_);
     
    }
    dfs(1);

    for(int i = 2; i<=N; i++)
        cout << parent[i] << "\n";
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