#include <iostream>

using namespace std;

long long dp[91];
int N;

void solve()
{
    cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for(int i=4; i<91;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[N];

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}