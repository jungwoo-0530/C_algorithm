#include<iostream>
#include<string.h>

using namespace std;

int Testcase;
int dp1[40];//1의 갯수
int dp0[40];//0의 갯수

void solve()
{
    dp1[0] = 0;
    dp1[1] = 1;
    dp0[0] = 1;
    dp0[1] = 1;
    for(int i=2; i<=40; i++)
    {
        dp1[i] = dp1[i-1] + dp1[i-2];
        dp0[i] = dp0[i-1] + dp0[i-2];
    }

    cin >> Testcase;

    for(int i=0; i<Testcase; i++)
    {
        int input;
        cin >> input;

        cout << dp0[input] << " " << dp1[input] << endl;
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}