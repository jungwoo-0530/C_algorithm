#include<iostream>
#include<queue>

using namespace std;

int map[500][500];
bool visit[500][500] = {false,};

int n, m;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};


int bfs(int y, int x){

    queue<pair<int,int>> q;
    q.push(make_pair(y, x));
    visit[y][x] = true;
    int cnt = 0;

    while(!q.empty()){

        int cY = q.front().first;
        int cX = q.front().second;
        q.pop();

        for(int i = 0; i<4; i++){
            int ny = cY + dy[i];
            int nx = cX + dx[i];

            if(ny >= n || nx >= m || nx < 0 || ny < 0)
                continue;
            if(map[ny][nx] != 1)
                continue;
            if(visit[ny][nx] == true)
                continue;
            
            visit[ny][nx] = true;
            cnt++;

            q.push(make_pair(ny, nx));
        }

    }

    return cnt;

}


void solve(){


    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
        }
    }
    int pictureCnt = 0;
    int pictureMaxSize = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(visit[i][j] == false && map[i][j] == 1){
                int size = bfs(i, j);
                pictureCnt++;
                if(pictureMaxSize < size)
                    pictureMaxSize = size;
            }
        }
    }

    cout << pictureCnt << "\n";
    cout << pictureMaxSize;
}

int main(){

    solve();

    return 0;


}