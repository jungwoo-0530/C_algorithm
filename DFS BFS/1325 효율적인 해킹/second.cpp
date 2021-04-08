#include <iostream>
#include <vector>
#include <string.h>
#include <deque>
#include <map>

using namespace std;

vector<int> conn[10001];
map<int, int>answer;
bool visit[10001];
int ans_int = 0;
int N;
int M;

void dfs(int k)
{
    visit[k] = true;
    
    for(int i = 0; i < conn[k].size(); i++)
    {
        if(visit[conn[k][i]] == false){

            ans_int++;
            dfs(conn[k][i]);
    
        }
    }
}


void solve()
{

    cin >> N >> M;
    int max_ans = 0;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        conn[b].push_back(a);
    }
    for(int i = 1; i <= N; i++)
    {
        memset(visit, false, sizeof(visit));
        dfs(i);
        answer.insert(make_pair(i, ans_int));
        if(max_ans < ans_int)
        {
            max_ans = ans_int;
        }
        ans_int = 0;
    }
    for(int i = 1; i <= N; i++)
    {
        if(answer[i] == max_ans)
            cout << i << " ";
            //answer.erase(i); 삭제하고 나중에 출력 가능.
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