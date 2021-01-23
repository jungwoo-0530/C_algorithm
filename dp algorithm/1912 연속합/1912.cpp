#include<iostream>

using namespace std;


int N;
int dp[100000];
int input[100000];
int maxvalue;
int MAX(int a, int b)
{
    if(a >= b)
        return a;

    else
        return b;
}

void solve()
{
    cin >> N;

    for(int i = 0; i<N; i++)
    {
        int a;
        cin >> a;
        input[i] = a;
        if(i == 0)maxvalue=a, dp[0] = a;
    }
    
    for(int i=1; i<N; i++)
    {
        dp[i] = MAX(input[i], input[i]+dp[i-1]);
        if(dp[i] > maxvalue)
            maxvalue = dp[i];
    }

    cout << maxvalue;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}