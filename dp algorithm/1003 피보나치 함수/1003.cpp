#include<iostream>

using namespace std;

int one, zero;
int Testcase;

int fibonacci(int n)
{
    if (n == 0)
    {
        zero++;
        return 0;
    }
    else if (n == 1)
    {
        one++;
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void solve()
{
    cin >> Testcase;

    for(int i=0; i<Testcase; i++)
    {
        int input = 0;
        one = 0, zero = 0;
        cin >> input; 
        fibonacci(input);
        cout << zero << " " << one << endl;
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}