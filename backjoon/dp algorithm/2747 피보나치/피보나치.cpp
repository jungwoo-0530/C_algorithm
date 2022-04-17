#include<iostream>

using namespace std;

int dp[100] = {0};
int num;

int pibo(int v)
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
   
   for(int i = 3; i<=v; i++)
   {
       dp[i] = dp[i-1]+ dp[i-2];
   }
   return dp[v];

}

int main()
{
    cin >> num;

    cout << pibo(num);

    return 0;
}