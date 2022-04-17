# [3055.탈출](https://www.acmicpc.net/problem/3055)



## 문제해결

- 고슴도치가 비버 굴로 가는 맵에서 가장 빠른 시간을 출력하는 문제이므로 BFS를 사용
- 물이 찬 곳은 비버가 가지 못하고 물은 시간이 갈 수록 상하좌우로 퍼지므로 BFS에서 먼저 물을 퍼트린 다음에 비버가 움직일 수 있는 곳을 이동하면서 ans배열에 값을 이동하기 전 배열에 +1하여 시간을 체크한다.
- 중요한 것은 BFS while문에서 물과 비버의 for문의 위치가 중요. 나머지는 평소 최소거리구하는 문제랑 같게 하면 된다.



```
int bfs(int sx, int sy)

{
​    visit[sx][sy] = true;
​    queue<pair<int,int>>here;
​    here.push(make_pair(sx,sy));
​    
​    while(!here.empty())
​    {
​        //물이동후에 고슴도치 이동(고슴도치 이동방향이 물이 찰 예정이면 안되므로 물을 먼저 채운다.)

​        int water_loop = water.size();
​        for(int j=0; j<water_loop;j++)
​        {

​            int w_x = water.front().first, w_y = water.front().second;

​            water.pop();
​                for (int i = 0; i < 4; i++) //물이동.
​                {
​                    int wx = w_x + dx[i], wy = w_y + dy[i];
​                    if (wx > R - 1 || wy > C - 1 || wx < 0 || wy < 0)continue; //물의 이동이 맵 범위를 넘어서면 스킵.
​                    if (adj[wx][wy] == '*' || adj[wx][wy] == 'D' || adj[wx][wy] == 'X' || adj[wx][wy] == 'S')
​                        continue; //새로 이동하는 공간이 물이 이미 차있는 공간이거나 비버굴이거나 돌이면 스킵
​                        adj[wx][wy] = '*', water.push(make_pair(wx, wy)); //시작점이 물이고 새로운 위치가 비어있는 공간(.)이라면      맵에 물을 채우고 water 맵에 트루.

​                }
​        }
​        int here_size = here.size();
​        for(int m=0; m<here_size;m++)
​        {
​            int x = here.front().first, y = here.front().second;
​            here.pop();
​            for(int i=0; i<4; i++)//고슴도치이동.
​            {
​                int nx = x + dx[i], ny = y + dy[i];
​                if(nx > R - 1 || ny > C - 1 || nx < 0 || ny < 0)//새로운 고슴도치 이동이 맵을 넘어서면 스킵
​                    continue;       

​                if(adj[nx][ny] == '*' || adj[nx][ny] == 'X')continue;//고슴도치 새로운 이동이 물이거나 돌이면 스킵.

​                if(ans[nx][ny] == -1)

​                {

​                    ans[nx][ny] = ans[x][y] + 1;

​                    here.push(make_pair(nx,ny));

​                    if(adj[nx][ny] == 'D')return ans[nx][ny];

​                }

​            }

​        }

​    }

​    return 0;

}


```

