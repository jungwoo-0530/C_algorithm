#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

vector<int>map[1001];
int Testcase;
int N;
int count_;
int visit[1001];

void solve(int a)
{
    visit[a] = 1;

    for(int i = 0; i < map[a].size(); i++)
    {
        if(visit[map[a][i]] == 0)
        {
            solve(map[a][i]);
        }
    }   
}


int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Testcase;

    for(int i = 0; i < Testcase; i++)
    {
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        count_ = 0;
        cin >> N;
        for(int i = 1; i <= N; i++)
        {
            int a;
            cin >> a;
            map[i].push_back(a);
            map[a].push_back(i); 
        }
        for(int j = 1; j<= N; j++)
        {
            if(visit[j] == 0)
            {
                solve(j);
                count_++;
            }
        }
        cout << count_ << endl;
        
    }
    return 0;
}