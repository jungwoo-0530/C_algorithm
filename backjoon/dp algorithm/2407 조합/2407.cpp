#include <iostream>

using namespace std;
//조합
//nCr = n!/(r!(n-r)!)
// 

int n,m;//n>=m, 5<=n<=100 100!팩토리얼을 저장.
//m,n >= 5.
unsigned long long factorial[101];
long long dp[101][101];
//factorial[i] = factorial[i-1]*i;
//fact[n][m] = 
void solve()
{
    factorial[0] = 0;
    factorial[1] = 1;
    for(int i=5; i<=100; i++)
    {
        for(int j=5; j<=i; j++)
        {
            dp[i][j] = 
        }
    }

    cin >> n >> m;

    cout << factorial[50];
    
    //cout << factorial[n]/(factorial[m]*(factorial[n-m]));

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}