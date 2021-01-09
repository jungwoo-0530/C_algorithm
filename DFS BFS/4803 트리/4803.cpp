#include<iostream>
#include<vector>
#include<string.h>

using namespace std;


vector<vector<int>>adj;
bool visit[501];
int n, m;
int a, b;
int Casenum;
int tree_cnt;
int edge_cnt;
int vertex_cnt;
//트리 조건 : 트리는 정점이 n개, 간선이 n-1개.
//          임의의 두 정점에 대해서 경로가 유일하다.
//무방향 그래프는 간선/2, 방향 
void dfs(int u)
{   
    visit[u] = true;
    edge_cnt++;

    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(!visit[v])
        {
            edge_cnt++;
            vertex_cnt++;
            dfs(v);
        }
    }
}


void solve()
{
    while(1)
    {  
        Casenum++;
        memset(visit, false, sizeof(visit));
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
                if(edge_cnt -1 == vertex_cnt)
                    tree_cnt++;
            }
            edge_cnt = 0;
            vertex_cnt = 0;
        }
        cout << "Case" << " " << Casenum << ":" << " ";
        if(tree_cnt > 1)
            cout << "A forest of" << " " << tree_cnt << " " << "trees."<<endl;
        else if(tree_cnt == 1)
            cout << "There is one tree."<<endl;
        else
            cout << "No trees."<< endl;
        tree_cnt = 0;
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();

    return 0;
}