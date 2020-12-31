#include<iostream>
#include<vector>
#include<queue>
using namespace std;

char node[26][3];
int N;
int v[26];

void InputNode()
{   
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j< 3; j++)
        {
            cin >> node[i][j];
        }
    }
}

void Post(int num)
{
    memset(v, 0, sizeof(v));
    cout<<node[num][0];
    Post()


}

void solve()
{
    cin >> N;
    InputNode();
    Post(0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}