#include <iostream>

using namespace std;

int N;
long long dp[1000001];

void solve()
{
    cin >> N;
    

    dp[1] = 1;//1
    dp[2] = 2;//11, 2
    dp[3] = 4;//111, 12, 21, 3;

    for(int i=4; i<1000001; i++)
    {
        dp[i] = dp[i-1]+dp[i-2] +dp[i-3];
        dp[i] %= 1000000009;
    }

    for(int i=0; i<N; i++)
    {
        int a;
        cin >> a;
        cout << dp[a]<<endl;
    }
        
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}