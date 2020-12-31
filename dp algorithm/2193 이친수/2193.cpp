#include<iostream>

using namespace std;

long long num;
long long dp[90];


long long solve(int a)
{
    dp[0]=1;
    dp[1]=1;
    for(int i = 2; i<a; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[a-1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;
    solve(num);
    cout << dp[num-1];

    return 0;
}
//함수를 cout에서 바로 출력과 차이.