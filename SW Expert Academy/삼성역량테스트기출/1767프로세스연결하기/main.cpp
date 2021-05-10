#include<iostream>
#include<vector>
using namespace std;

#define MAX 12
//1. 한개 cell에는 1개의 코어 또는 1개의 전선이 올 수 있음
//2. 멕시 노스의 가장 자리에는 전원이 흐르고 있음
//3. core는 전선 연결은 직선만 가능
//4. 전선 교차 x
//5. 가장자리 core는 연결된 것으로 간주
//dfs 종료 조건 : 1. 설치한 코어 갯수가 전에 설치한 코어 갯수보다 많다면 넣는다
//              2. 설치한 코어 갯수가 전에 설치한 코어 갯수랑 같다면 전선 길이 비교해서 넣는다.

int map[MAX][MAX];
int N;
int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};
vector<pair<int,int>>core_point;
int answer_wire;
int answer_core;

//index : core 번호.
//ins : 코어 설치 갯수.
//sum : 전선 길이.
void dfs(int index, int ins, int sum)
{

    if(index == core_point.size())//모든 코어를 다 들렀을때
    {
        if(ins > answer_core)//기존 코어 설치 갯수보다 많이 설치할 경우.
        {
            answer_core = ins;
            answer_wire = sum;
        }
        else if(ins == answer_core)//기존 코어 설치 갯수와 같다면 최소 전선길이.
        {
            answer_core = ins;
            answer_wire = min(answer_wire, sum);
        }
        return;

    }

    for(int i = 0; i<4; i++)
    {
        vector<pair<int,int>>tmp;//전선 한칸씩 넣는 벡터
        int nx = core_point[index].first;
        int ny = core_point[index].second;
        bool flag = false;

        while(1)
        {
            if(nx==0 || ny ==0|| nx == N-1 || ny == N-1)//가장자리까시 전선을 연결했으면 flag = true로해주고
                                                        //break;
            {
                flag = true;
                break;
            }

            nx += x[i];
            ny += y[i];

            if(map[nx][ny] == 0)//전선연결 루트가 0일경우 전선 위치를 벡터에 넣는다.
            {
                tmp.push_back(make_pair(nx,ny));
            }
            else
            {
                break;
            }
        }
        if(flag)//flag가 true면 전선설치. 여기서 연결하고 dfs, 백트래킹
        {
            for(int j = 0; j<tmp.size(); j++)//map에 전선설치한 부분을 2로.
            {
                map[tmp[j].first][tmp[j].second] = 2;
            }

            dfs(index+1, ins+1, sum+(int)tmp.size());

            for(int j = 0; j<tmp.size(); j++)//백트래킹
            {
                map[tmp[j].first][tmp[j].second] = 0;
            }

        }





    }
    //전선 연결안하는경우
    dfs(index + 1, ins, sum);

}

void solve()
{
    int testcase;
    cin >> testcase;
    for(int tc = 1; tc <= testcase; tc++)
    {
        cin >> N;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cin >> map[i][j];
                if(map[i][j] == 1 && (i != 0 && j != 0 && i != N-1 && j != N-1))
                    core_point.push_back(make_pair(i,j));
            }
        }
        answer_core = 0;
        answer_wire = 1e9;
        dfs(0,0,0);

        cout << "#"<<tc << " " <<answer_wire<<endl;

        core_point.clear();
    
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}