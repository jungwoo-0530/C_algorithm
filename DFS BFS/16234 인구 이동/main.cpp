#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int map[50][50] = {-1, };
int N, L, R;// 인구 차이가 L 이상 R 이하일때 일어남.
bool visit[50][50] = {false, };
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<pair<int, int> >temp;

int answer;
int cnt;
int day = 0;


bool sub(int a, int b)
{
    if(a > b){
        if((a-b) <= R && (a-b) >= L)
            return true;
    }
    else if(a < b)
    {
        if((b-a) <= R && (b-a) >= L)
            return true;
    }
    else
        return false;

    return false;
}

void dfs(int x, int y, int ans)
{
    visit[y][x] = true;
    cnt++;
    answer += ans;
    //[dy][dx]
    for(int i = 0; i<4; i++){
        int nx = x+dx[i];//열
        int ny = y+dy[i];//행

        if(ny < 0 || ny > N-1 || nx > N-1 || nx < 0)
            continue;
        if(visit[ny][nx] == true)
            continue;

        if(sub(map[ny][nx], map[y][x]))//국경열기.
        {
            visit[ny][nx] = true;
            temp.push_back(make_pair(ny, nx));
            dfs(nx, ny, map[ny][nx]);
        }

    }
}


int main(){


    cin >> N >> L >> R;

    for(int i = 0; i < N; i++){
        for(int j = 0; j<N; j++){
            cin >> map[i][j];
        }
    }
int flag = false; //연합했는지 안했는지.
while(1)
{
    flag = false;

    day++;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(visit[i][j] == false)
            {
                temp.push_back(make_pair(i,j));
                dfs(j, i, map[i][j]);
                int num = answer/cnt;
                for(int k = 0; k<cnt; k++){  
                    map[temp[k].first][temp[k].second] = num;
                }
            }
            if(cnt > 1){
                flag = true;
            }            

            temp.clear();
            answer = 0;
            cnt = 0;
        }
    }
    if(flag == false)
    {
        day--;
        break;
    }
    memset(visit, false, sizeof(visit));

}

cout << day;

            return 0;
}