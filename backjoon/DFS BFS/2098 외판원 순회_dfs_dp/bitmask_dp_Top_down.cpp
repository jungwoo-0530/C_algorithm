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
// dp[i][j] = 이미 방문한 도시들의 집합이 j이고 현재 있는 도시가 i일때, 방문하지 않은 나머지 도시들을 모두 방문한 뒤 출발 도시로 돌아올 때 드는 최소 비용.
//즉, dp[현재위치][방문한state] = 현재 위치로부터 최종도착지(출발지점)으로 가는 최소비용.
//tree로 치면, dfs로 이용해 leaf까지 간다음 올라오면서 최소 비용을 계속 업데이트, 리턴하면서 전체를 여행하는 모든 경우의 수의 최소비용을 찾는다.
int dp[16][1<<16];
int ans = 999999;
//state : 현재까지 방문한 도시상태.
//now 이번에 지날 도시 번호.
int dfs(int state, int now){

    //이번에 지날 도시를 state에 추가.
    state = state|(1<<now);

    //모든 도시를 방문 했으면. 4개도시라면 1 + 2 + 4 + 8 = 15, 1<<4는 16.
    if(state == (1<<n)-1){
        //현재 위치에서 최종도착지(출발지점, 0번도시)로 갈 수 있다면.
        if(W[now][0] > 0){
            return W[now][0];
        }
        return MAX;//base condition
    }

    int &ret = dp[now][state];
    //중요! memorization.
    if(ret > 0){
        return ret;
    }
    ret = MAX;

    for (int next = 0; next < n; next++)
    {
        //아직 방문하지 않은 i번 도시 가는 경로가 있을 경우.
        // next가 현재 가있는 도시(now)이면 안되고
        // state에 없으며 = 가지않은도시
        //지나갈 수 있는 도시이면 = now에서 next로.
        if (next != now && !(state & 1 << next) && W[now][next] > 0)
        {
            // cout << i << endl;

            int temp = dfs(state, next) + W[now][next];
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
    if(a == MAX)cout << -1;
    cout << a;

}


int main(){

    solve();

    return 0;
}