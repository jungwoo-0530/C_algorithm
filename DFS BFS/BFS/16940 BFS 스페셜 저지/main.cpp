#include<iostream>

using namespace std;
#define MAX_VERTEX 100001
int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];
int temp[MAX_VERTEX];
int queue[MAX_VERTEX];
int vertex, edge,  start;



int BFS (int v)
{
    visit[v] = 1;
    int rear = 0; int front = 0;
    int t;
    int k;
    int check = 1;
    queue[rear++] = v;

    for(int j = 1; j<=vertex;j++)
    {
        t = queue[front++];
        for(int i = 1; i<=vertex; i++)
        {   
            if(map[t][i]==1 && visit[i]==0 && i == temp[j])
            {
                queue[rear++] = i;
                visit[i] = 1;
                check++;
            }   
        }
    }
    if(check == vertex)
        return 1;

    else
        return 0;
}

int main()
{
    cin >> vertex;
    edge = vertex-1;
    int row,column;

    for(int i = 1; i < vertex+1; i++)
    {
        for(int j = 1; j<vertex+1; j++)
        {
            map[i][j] = 0;
            
        }
        visit[i] = 0;
        queue[i] = 0;
    }

    for(int i = 0; i < edge; i++)
    {
        cin >> row >> column;
        map[row][column] = map[column][row] = 1;
    }

    for(int k = 1; k <= vertex; k++)
    {
        cin >> temp[k];
    }

        cout << BFS(temp[1]);

    
    return 0;

}