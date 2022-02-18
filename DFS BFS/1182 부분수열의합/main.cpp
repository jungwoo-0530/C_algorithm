#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;


int visit[2<<20];
int N, S;
int val[20];
int ans = 0;

void dfs(int state){

    if(visit[state])return;

    visit[state] = 1;

    int result = 0;
    for(int i = 0; i<N; i++){
        if(state &(1<<i)){
            result += val[i];
        }
    }
    if(result == S){
        ans++;
    }

    for(int i = 0; i<N; i++){
        if(state & (1<<i))continue;
        dfs(state | 1<<i);
    }

}


int main(){

    cin >> N >> S;

    fill(val, val+N, -1);

    for(int i = 0; i<N; i++){
        cin >> val[i];
    }

    for(int i = 0; i<N; i++){
        int a = pow(2, i);
        dfs(a);
    }

    cout <<ans;

    return 0;
}