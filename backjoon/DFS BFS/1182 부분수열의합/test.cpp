#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int visit[2 << 20];
int N, S;
int val[20];
int ans = 0;

void dfs(int state)
{

    if (visit[state])
        return;

    visit[state] = 1;

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (state & (1 << i))
        {
            result += val[i];
        }
    }
    if (result == S)
    {
        ans++;
    }

    for (int i = 0; i < N; i++)
    {
        if (state & (1 << i))
            continue;
        dfs(state | 1 << i);
    }
}

int main()
{

    // cin >> N >> S;

    // fill(val, val + N, -1);

    // // for (int i = 0; i < N; i++)
    // // {
    // //     cin >> val[i];
    // // }
    // cout << (2<<N) << endl;
    // cout << (1<<N) << endl;

    // // cout << ans;

    int a;
    cin >> a;

    for(int i = 0; i<1<<a; i++){
        cout << i<<endl;
    }


    return 0;
}