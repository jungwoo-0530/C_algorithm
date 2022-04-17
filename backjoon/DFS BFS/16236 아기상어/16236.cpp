#include<iostream>
#include<vector>
#include<string.h>

using namespace std;


vector<int>map[20];
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};
int size = 2;
int N;
int visit[20][20];
int Time = 0;

void solve()
{
    cin >> N;
    
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            int a;
            cin >> a;
            map[i].push_back(a);
        }
        
    }

    while(1)
    {
        if()
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    solve();

    return 0;
}