#include<iostream>
#include<vector>

#define MAX 1000001

using namespace std;

int N;//시험장
vector<long long>num;//시험장마다 수험생수
long long master;//감독관이 감시할 수 있는 수험생수
long long sub;//부감독관이 감시할 수 있는 수험생수
long long answer;

void mast()
{
    //감독관 수
    answer += N;
    for (int i = 0; i < N; i++)
    {
        num[i] -= master;

        if (num[i] < 1)
        {
            num.erase(num.begin() + i);
        }
    }
}

void sub_()
{
    for (int i = 0; i < num.size(); i++)
    {
        long long a;
        a = num[i] / sub;
        num[i] -= a * sub;
        if (num[i] > 0)
        {
            answer += a + 1;
        }
        else
        {
            answer += a;
        }
    }
}


void solve()
{

    cin >> N;
    long long temp;
    for(int i = 0; i<N; i++)
    {
        cin >> temp;
        num.push_back(temp);
    }

    cin >> master >> sub;


    // if(master < sub)
    // {
    //     sub_();
    //     mast();
    // }

    // else
    // {
    //     mast();
    //     sub_();
    // }

    //감독관 수
    
    for (int i = 0; i < N; i++)
    {
        num[i] -= master;
        answer ++;

        if(num[i] > 0)
        {
            if(num[i]%sub == 0)
            {
                answer += (num[i]/sub);
            }
            else{
                answer += (num[i]/sub)+1;
            }
        }
    }
    cout << answer;

}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}