#include <iostream>
#include <math.h>

using namespace std;


int dp[32769];
//2^15 = 32768
//라그랑주의 네 제곱 : 모든 수는 4개의 제곱수로 표현
// 3 = 1^2+1^2+1^2+0^2
//
//

void solve()
{

    while(1)
    {
        int a;
        cin >> a;
        if(a==0)break;
        int cnt = 0 ;
        int b = sqrt(a);

        for(int i=1; i<=b; i++)
        {
            if(i*i == a)
            {
                cnt++;
                continue;
            }
           
           for(int j=i; j<=b; j++)
           {
               if(i*i + j*j == a)
               {
                   cnt++;
                   break;
               }
               

                for(int k=j; j<=b; k++)
                {
                    if(i*i + j*j + k*k == a)
                    {
                        cnt++;
                        break;
                    }

                    for(int h=k; h<=b; h++)
                    {
                        if (i * i + j * j + k * k + h*h == a)
                        {
                            cnt++;
                            break;
                        }
                    }
                }

           }
            
        }

        cout << cnt << endl;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}