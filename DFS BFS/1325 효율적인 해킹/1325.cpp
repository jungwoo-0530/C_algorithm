#include<iostream>
#include<vector>
#include<string.h>
#include<deque>


using namespace std;


vector<int>conn[10001];
deque<pair<int,int>>ans;
int visit[10001];
int result[10001];
int ans_int=0;
int N;
int M;


void dfs(int k)
{
    visit[k] = 1;
    ans_int++;
    for(int i = 0; i < conn[k].size(); i++)
    {
        if(visit[conn[k][i]] == 1)continue;
        dfs(conn[k][i]);

    }

}


void solve()
{

    cin >> N >> M;

    for(int i = 1; i <=M; i++)
    {
        int a, b;
        cin >> a >> b;
        conn[b].push_back(a);
    }
    int index = 0;
    int temp = 0;
    for(int i = 1; i <= N; i++)
    {
        memset(visit, 0, sizeof(visit));
        dfs(i);
        ans.push_back(make_pair(i,ans_int));
        ans_int = 0;
    }
    int high_score = ans.front().second;
    result[0] = ans.front().first;
    int flag = 0;
    for(int i = 0; i < N; i++)
    {
        if((ans.begin()+i)->second > high_score)
        {
            high_score = (ans.begin()+i)->second;
            result[0] = i+1;
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(high_score == (ans.begin()+i)->second)
            cout << (ans.begin()+i)->first << " ";
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