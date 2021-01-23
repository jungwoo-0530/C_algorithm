#include<iostream>

using namespace std;

int N;
int dp[10001];//최댓값
int input[10001];//input값

int bigger(int a, int b)
{if(a>=b)return a; else return b;}

void solve()
{
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        int a;
        cin >> input[i];
    }
    dp[1] = input[1];
    dp[2] = input[1]+input[2];
    for(int i=3; i<=N; i++)
    {
        dp[i] = bigger(dp[i-3]+input[i-1]+input[i], bigger(dp[i-2]+input[i], dp[i-1]));
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