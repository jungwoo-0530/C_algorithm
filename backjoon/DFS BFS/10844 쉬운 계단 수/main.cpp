#include<iostream>

using namespace std;

//12, 23, 34, 45, 56, 67, 78, 89 8개
//21, 32, 43, 54, 65, 76, 87, 98 8개
//10
int n;

int dfs(int deep, int state){



    for(int i = 0; i<10; i++){

        if(deep = 0 && i == 0){
            continue;
        }

        dfs(deep+1,)

    }


    return 0;
}

void solve(){

    cin >> n;

    int ans = dfs(n, 0);
    ans /= 1000000000;

    cout << ans;

}



int main(){

    solve();

    return 0;

}