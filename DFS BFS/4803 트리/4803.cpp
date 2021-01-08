#include<iostream>
#include<vector>
#include<string.h>

using namespace std;


vector<vector<int>>adj;
bool visit[501];
bool finish[501];
int n, m;
int a, b;
int Casenum;
int cnt;
bool chk;
void dfs(int u)
{   
    visit[u] = true;

    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        
        if(visit[v])
            chk = true;
        
        else if(!visit[v])
        {
            dfs(v);
        }
        else if(!finish[v])
            chk = true;
        
    }

    finish[u] = true;
}


void solve()
{
    while(1)
    {  
        Casenum++;
        memset(visit, false, sizeof(visit));
        memset(finish, false, sizeof(finish));
        chk = false;
        cnt = 0;
        cin >> n >> m;
        adj.assign(n + 1, vector<int>());
        if(n == 0 && m == 0)break;

        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 1; i <= n; i++)
        {
            if(!visit[i])
            {
                dfs(i);
                if(!chk)
                    cnt++;
                chk = false;
            }
        }
        cout << "Case" << " " << Casenum << ":" << " ";
        if(cnt > 1)
            cout << "A forest of" << " " << cnt << " " << "trees."<<endl;
        else if(cnt == 1)
            cout << "There is one tree."<<endl;
        else
            cout << "No trees."<< endl;
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();

    return 0;
}