#include<iostream>
#include<vector>
#include<string.h>


using namespace std;

int T, n;
vector<vector<int>>adj;
bool visit[100001];
bool finished[100001];
int cnt;
int P[100001];

void dfs(int start)
{
    visit[start] = true;

    for(int i = 0; i < adj[start].size(); i++)
    {
        if(!visit[adj[start][i]])
        {
            P[start] = adj[start][i];
            dfs(adj[start][i]);
        }
        else if(!finished[adj[start][i]])
        {    for(int j = adj[start][i]; j != start; j = P[j])
                cnt++;//자신의 부모를 차례대로 올라가면서 노드갯수 플러스.
            cnt++;//자기 자신을 플러스.
        }

    }

    finished[start] = true;

}


void solve()
{
    cin >> T;

    while(T--)
    {
        cin >> n;
        memset(visit, false, sizeof(visit));
        memset(finished, false, sizeof(finished));
        memset(P, 0, sizeof(P));
        adj.assign(n+1, vector<int>());
        cnt = 0;

        for(int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            adj[i].push_back(a);
        }

        for(int i = 1; i <= n; i++)
        {
            if (!visit[i])dfs(i);
        }

        cout << n - cnt << endl;
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