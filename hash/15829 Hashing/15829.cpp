#include <iostream>

using namespace std;

int N;
int r = 31;
int M = 1234567891;

void solve()
{
    cin >> N;

    long long int result = 0;
    int cnt = 0;
    for(int i=0; i<N; i++)
    {
        char a;
        cin >> a;

        long long  b;
        b = (int)a-96;
        if(cnt == 0)
        {
            result += b%M;
            cnt++;
        }
            
        else
        {
            for(int j=0; j<cnt; j++) 
                b = (b*r)%M;
            
            cnt++;
            result += b%M;
        }
        
    } 

    cout << result%M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}