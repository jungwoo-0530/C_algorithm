#include<iostream>

using namespace std;


//dp[i] = i원일 때 필요한 코인 수.
//coin 1, 2, 3
//dp[1] = dp[0] + 1 = 1
//dp[2] = dp[2] + dp[1+1], d[2] + dp[0+2] = 2
//if(i <= c[j]) dp[i] = dp[i] + dp[i-c[j]]
//dp[i] = dp[i-k]+ c[k]
//dp[0] = 0;




int dp[10001];
int c[20];
int N;
int M;
int T;



int bottom_up(){

    fill(dp, dp+10001, 0);

    dp[0] = 1;

    // for(int i = 1; i<=M; i++){
    //     for(int j = 0; j<N; j++){
    //         if(i >= c[j])
    //             dp[i] = dp[i] + dp[i-c[j]];
    //     }
    // }
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (i >= c[i])
                dp[j] = dp[j] + dp[j - c[i]];
        }
    }

    return dp[M];
}

int main(){


    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> c[i];
    }

    cin >> M;

    cout << bottom_up() <<endl;

    return 0;
}