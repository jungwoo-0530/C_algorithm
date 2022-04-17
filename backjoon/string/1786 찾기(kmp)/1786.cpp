#include<iostream>
#include<vector>

using namespace std;

//LPS를 구할때는 j,i로 시작한다.
//j는0에서시작 i는 1에서 시작, j는 접두사, i는 접미사
//i,j일치하는지 확인, i는 매번 1씩 증가
//i인덱스와 j인덱스 문자가 다를 경우, j인덱스의 값으로 이동하고 j와 i인덱스 비교
//i인덱스 문자와 j인덱스 문자가 같을 경우, j+1을 i인덱스값에넣는다.
vector<int> failfun(string a)//LPS
{
    int size = (int)a.size();
    int j = 0;
    int i = 1;
    vector<int>fail(size,0);

    for(i; i<size; i++)
    {
        while(j>0 && a[i] != a[j])
        {
            j = fail[j-1];
        }
        if(a[i] == a[j])//같다면 j를 증가시키고 j값을 저장.
            fail[i] = ++j;
        
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