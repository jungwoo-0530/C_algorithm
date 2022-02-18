#include <string>
#include <vector>
#include<iostream>

using namespace std;

int l[20], r[20], map[20];
int visit[1<<17];
int n;
int ans = 1;


void dfs(int state){


    if(visit[state])return;
    visit[state] = 1;


    int num = 0;//state의 정점들 총 갯수.
    int wolf = 0;//wolf 갯수.

    for(int i = 0; i<n; i++){
        //state에 i번째 비트가 불이 들어와있다면 해당 정점이 있다는 것.
        if(state & (1 << i)){
            num++;
            wolf += map[i];//양은 0, 늑대는 1이므로.
        }
    }

    if(wolf*2 >= num)return;
    if(ans < num-wolf)ans = num-wolf;

    for(int i = 0; i<n; i++){

        //현재상태에서 i번쨰 비트가 꺼져잇는 경우는 해당 정점이 없으니 스킵.
        if(!(state & (1 << i)))continue;

        //현재노드에서 왼쪽자식노드가 있다면
        if(l[i] != -1)
            dfs(state | (1 << l[i]));
        //현재노드에서 오른쪽자식노드가 있다면
        if(r[i] != -1)
            dfs(state | (1<<r[i]));

    }    

}

int solution(vector<int> info, vector<vector<int>> edges)
{

    n = info.size();
    fill(l,l+n,-1);
    fill(r,r+n,-1);
    for(int i = 0; i<n; i++)
        map[i] = info[i];
    for(int i = 0; i<n-1; i++){
        int a = edges[i][0]; //부모
        int b = edges[i][1]; //자식

        if(l[a] == -1)l[a] = b;
        else r[a] = b;
    }

    dfs(1);//0번노드가 들어간 상태이므로 1로시작.



    return ans;
}