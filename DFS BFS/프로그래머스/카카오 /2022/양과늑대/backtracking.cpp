#include <string>
#include <vector>

#include <iostream>

using namespace std;

int l[20], r[20], val[20];
int n;
int ans;
// bool visit[17];

void dfs(bool visit[17], int node)
{
    visit[node] = true;

    int num = 0;
    int wolf = 0;
    for(int i = 0; i<n; i++){
        if(visit[i] == true){
            wolf += val[i];
            num++;
        }
    }

    if (wolf * 2 >= num)
        return;
    if (ans < num - wolf)
        ans = num - wolf;

    for(int i = 0; i<2; i++){
        // if(visit[i] == true)continue;
        if(l[node] != -1 && visit[l[node]])dfs(visit, l[node]);
        if(r[node] != -1 && visit[r[node]])dfs(visit, r[node]);

    }

}

int solution(vector<int> info, vector<vector<int>> edges)
{
    n = info.size();
    fill(l, l+n, -1);
    fill(r, r+n, -1);
    // fill(visit, visit+n, false);

    for(int i = 0; i<n; i++){
        val[i] = info[i];
    }
    for(int i = 0; i<n-1; i++){
        int parent = edges[i][0];
        int child = edges[i][1];
        if(l[parent] == -1) l[parent] = child;
        else r[parent] = child;
    }

    bool visit[17] = {false,};
    dfs(visit, 0);


    cout << ans;

}