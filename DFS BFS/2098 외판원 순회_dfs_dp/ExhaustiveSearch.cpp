#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int>map[16];
vector<int>val[16];
bool visit[16] = {false,};
int ans = 999;

//dfs로 이용한 완전탐색. 
//그러나 시간초과.
//0번에서 갈 수 있는 곳은 0번을 제외한 n-1개.
//즉 모든 경우의 수를 따지는 완전탐색 할경우 o(n!)

void dfs(vector<int> vec, int deep){

    int ansTemp = 0;
    //0,1,2,3
    //0,1,2
    if(deep == n){
        //갈때.간선이므로 vec.size()-1.
        for(int i = 0; i<vec.size()-1; i++){
            int startNode = vec[i];
            int endNode = vec[i+1];
            int edgeWeight = map[startNode][endNode];
            ansTemp += edgeWeight;
        }

        ansTemp += map[vec[n-1]][vec[0]];
        if (ans > ansTemp)
        {
            ans = ansTemp;
        }
    }
    


    for(int i = 0; i<n; i++){
        if(!visit[i]){
            visit[i] = true;
            vec.push_back(i);
            dfs(vec, deep+1);
            vec.pop_back();
            visit[i] = false;

        }
    }

}

void solve(){

    cin >> n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int a;
            cin >> a;
            map[i].push_back(a);
        }
    }
    vector<int>temp;
    // temp.push_back(0);
    // visit[0] = true;
    dfs(temp, 0);
    cout << ans;
}


int main(){

    solve();


    return 0;
}