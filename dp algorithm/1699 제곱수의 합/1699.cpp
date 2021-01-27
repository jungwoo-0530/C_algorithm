#include <iostream>

using namespace std;

int dp[100001];

//짝수 + 홀수인경우 1을 사용.
//1. 1 ,2,3,4,5..의 제곱수는 무조건 dp[k]가 1 -> 4%2 = 0, 9
// 12 = 9+2+1 4+4+4
//2. 
void solve()
{
    int N;
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i=4; i<=100000;i++)
    {
        if(i)
        {

        }

        else
        {
            dp[i] = dp[i-1] + 1;
        }
        
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