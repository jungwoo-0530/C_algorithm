#include <iostream>

using namespace std;
//조합
//nCr = n!/(r!(n-r)!)
// 

int n,m;//n>=m, 5<=n<=100 100!팩토리얼을 저장.
unsigned long long factorial[101];
//factorial[i] = factorial[i-1]*i;

void solve()
{
    factorial[0] = 0;
    factorial[1] = 1;
    for(int i=2; i<=100; i++)
    {
        factorial[i] = factorial[i-1]*i;
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