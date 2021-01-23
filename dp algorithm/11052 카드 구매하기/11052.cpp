#include <iostream>

using namespace std;

int N;
int dp[1001];
int input[1001];

int bigger(int a, int b){if(a>b)return a; else return b;}

void solve()
{
    cin >> N;

    for(int i=1; i<=N; i++)
    {
        int a;
        cin >> input[i];
    }

    //총 4장이라고하면 N = 4
    //d[i] -> i개 카드를 선택하였을때 최댓값.
    //d[4] = dp[i-1] + input[1] , dp[i-2] + input[2], dp[i-3] + input[3], dp[i-4] + input[4]
    //d[i] = dp[i-1] + input[1] ,... , dp[i-i] + input[i]
    dp[0]=0;input[0]=0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=i; j++)
            dp[i] = bigger(dp[i], dp[i-j]+input[j]);
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