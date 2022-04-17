#include <string>
#include <vector>

using namespace std;

vector<int>map;
vector<int>tree[17];//tree[부모] 값들은 자식들.
bool visit[17] = {false,};
int ans = 1;

void dfs(vector<int>vec){


    //백트래킹. 유망한지 확인.
    int wcnt = 0; int scnt = 0;
    for(int i = 0; i < vec.size(); i++){
        //0은 양. 1은 늑대.
        int node = vec[i];
        if(map[node] == 0){
            scnt++;
        }else{
            wcnt++;
        }
    }

    //wolf가 sheep보다 같거나 큰 경우 양이 다 잡히므로 백트래킹.
    if(wcnt >= scnt){
        return;
    }
    //아닐경우는 양의 수 저장.
    else{
        if(ans < scnt){
            ans = scnt;
        }
    }


    //파라미터로 들어온 vec(현재 push된 노드들)에서 자식노드들을 탐색.
    for(int i = 0; i<vec.size(); i++){
        int parent = vec[i];
        //parent의 자식노드.
        for(int j = 0; j<tree[parent].size(); j++){

            int child = tree[parent][j];
            if(!visit[child]){
                vec.push_back(child);
                visit[child] = true;
                dfs(vec);
                visit[child] = false;
                vec.pop_back();
            }
        }
    }

}

int solution(vector<int> info, vector<vector<int> > edges)
{

    for(int i = 0; i<info.size(); i++){
        map.push_back(info[i]);//info순서가 0번노드부터 0,1값이 들어가므로.
    }

    //tree index값에 부모, 값에 자식
    for(int i = 0; i<edges.size();i++){
        tree[edges[i][0]].push_back(edges[i][1]);
    }

    vector<int>temp;
    //무조건 루트노드인 0번 노드부터 시작하므로.
    temp.push_back(0);
    visit[0] = true;
    dfs(temp);

    return ans;
}