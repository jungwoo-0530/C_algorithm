#include<vector>
#include<string>
#include<iostream>

using namespace std;
#define MAX 17000000

//bitmask와 dp를 사용한 것.메모라이제이션
//재귀를 사용할 것이므로 top-down방식.
//Bottom-up인 반복문을 사용해서 했을 경우에는 출발 지점으로부터 계산했지만
//Top-down방식이므로 마지막부터 돌아오면서 계산.

int n;
// vector<int>map[16];
int W[17][17];
//첫번쨰 인덱스 : 현재 방문한 도시 번호, 두번째 인덱스 : 현재까지 방문한 도시상태.
int dp[16][1<<16];
int ans = 999999;
//state : 현재까지 방문한 도시상태.
//city 이번에 지날 도시 번호.
int dfs(int state, int city){

    //이번에 지날 도시를 state에 추가.
    state = state|(1<<city);

    //모든 도시를 방문 했으면. 4개도시라면 1 + 2 + 4 + 8 = 15, 1<<4는 16.
    if(state == (1<<n)-1){
        //다시 city -> 0번으로 돌아올때.
        if(W[city][0] > 0){
            return W[city][0];
        }
        return MAX;
    }


    int& ret = dp[city][state];
    //중요! memorization.
    if(ret > 0){
        return ret;
    }
    ret = MAX;

    for(int i = 0; i<n; i++){
        //아직 방문하지 않은 i번 도시 가는 경로가 있을 경우.
        //i가 현재 가있는 도시이면 안되고
        //state에 없으며 = 가지않은도시
        //지나갈 수 있는 도시이면 = city에서 i로.
        if(i != city && !(state&1<<i) && W[city][i] > 0){
            cout << i << endl;

            int temp = dfs(state,i) + W[city][i];
            if(ret > temp)//최소비용 업데이트.
                ret = temp;
        }

    }
    return ret;

}

void solve(){

    cin >> n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){

            int a;
            cin >> a;
            // map[i].push_back(a);
            W[i][j] = a;
        }
    }

    int a = dfs(0, 0);

}


int main(){

    solve();

    return 0;
}