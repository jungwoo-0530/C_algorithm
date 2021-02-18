#include<iostream>
#include<vector>

using namespace std;

vector<int> failfun(string a)
{
    int size = (int)a.size();
    int j = 0;

    vector<int>fail(size,0);

    for(int i=1; i<size; i++)
    {
        while()
        if(a[i] == a[j])
        {
            j++;
            fail[i] = j;
        }
     }
    
    return fail;
}

void solve()
{
    string a;

    cin >> a;

    vector<int> b = failfun(a);

    for(int i=0; i<b.size();i++)
    {
        cout << b[i] << " ";
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}