#include<iostream>
#define MAX_VERTEX 1001

using namespace std;

int map[MAX_VERTEX][MAX_VERTEX];//간선 테이블
int visit[MAX_VERTEX];//방문한 노드이면 1로 방문 안된 노드면 0
int  vertex, edge, start;//N 엣지 갯수, M 간선 갯수, V 시작 정점.
///////////////////////////////////////////////////////////////
//bfs는 dfs에서 추가로 큐배열과 rear, front 필요
int rear, front;
int queue[MAX_VERTEX];


void DFS(int v)//int v는 시작 노드번호
{
    
    visit[v] = 1;
    int i = 1;
    for(int i = 1; i<=vertex; i++ )
    {   
        if(map[v][i] == 1 && visit[i]==0 )
        {
            cout << i << " ";
            DFS(i);
        }
    }

}
//BFS는 rear 넣는 곳, front 빼는 곳. 넣는 순서대로 빠져나간다 . 큐.
void BFS(int v)
{
    rear = front = 0;
    int temp;
    visit[v] = 1;
    cout << v << " ";
    queue[rear++] = v;
    while(front < rear)
    {
        temp = queue[front++];
        for(int i = 1; i <= vertex; i++)
        {   
            if(map[temp][i] == 1 && visit[i] == 0)
            {
                cout << i << " ";
                visit[i] = 1;
                queue[rear++] = i;
            }
        }
    }

}

int main()
{
    
    int v1, v2;
    cin >> vertex >> edge >> start;


    for(int i =1; i<= vertex; i++)
    {   
        for(int j = 1; j<=vertex; j++)
        {
            map[i][j] = 0;
        }
        visit[i]=0;
        queue[i]=0;
    }
    for(int k =0; k < edge ; k++)
    {
        cin >> v1 >> v2;
        map[v1][v2] = map[v2][v1] = 1;

    }
    cout << start << " ";
    DFS(start);
    cout<<endl;
    for(int i = 0; i<= vertex; i++)
    {
        visit[i] = 0;
    }
    BFS(start);
    cout << endl;
    return 0;
}