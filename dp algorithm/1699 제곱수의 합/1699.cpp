#include <iostream>
#include <math.h>

using namespace std;

int dp[100001];

//짝수 + 홀수인경우 1을 사용.
//1. 제곱인 수는 무조건 1
//2. 8인 수를 보면 
//  1+1+1+1+1+1+1+1은 1의 경우의 수에서 7개 항을 더한 것이므로 8
//  4+4은 dp[4] + 1
// dp[8] = min(dp[7]+1, dp[4])

int min1(int a, int b){if(a > b)return b; else return a;}

void solve()
{
    int N;
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=4; i<=N;i++)
    {
        dp[i] = i;
        for(int j=1; j<=sqrt(i); j++)
            dp[i] = min1(dp[i], dp[i-j*j]);
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