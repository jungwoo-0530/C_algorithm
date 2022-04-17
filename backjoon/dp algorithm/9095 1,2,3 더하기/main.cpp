#include<iostream>

using namespace std;


int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int N;
    int key;
    int dp[12];
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;


    for(int i = 4; i<= 11; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    scanf("%d",&N);
    for(int i = 0; i<N; i++)
    {
        scanf("%d",&key);
        printf("%d\n",dp[key]);
    }


    

    return 0;
}