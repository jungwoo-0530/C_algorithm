#include<iostream>

using namespace std;

int max(int a, int b)
{
    if(a > b)
        return a;

    else
        return b;
}

int main()
{
    int N;
    int i, j;
    int max_answer = 0;
    int dp[500][500];

    scanf("%d",&N);

    for(i = 0; i<N; i++)
        for(int j = 0; j<=i; j++)
            scanf("%d",&dp[i][j]);
    max_answer = dp[0][0];

    for(i = 1; i<N; i++)
        for(j = 0; j <= i; j++)
        {
            if(j == 0) dp[i][j] = dp[i-1][0] + dp[i][j];
            else if(i==j) dp[i][j] = dp[i-1][j-1] + dp[i][j];
            else dp[i][j] = dp[i][j] + max(dp[i-1][j-1], dp[i-1][j]);

            max_answer = max(dp[i][j], max_answer);
        }

    printf("%d\n",max_answer);


    return 0;
}