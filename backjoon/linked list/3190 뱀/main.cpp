#include<iostream>
//NxN박스.
//L 왼쪽 90도 D 오른쪽 90도
// 벽 또는 자기 자신의 몸에 부딪히면 게임 끝.
using namespace std;

struct Node
{

   Node* next;
};

Node* head;
Node* tail;


int main()
{
    int N = 0;//NxN 매트릭스
    int apple = 0;
    int row, col;
    int mov;//뱀 방향전환 횟수
    int second;
    char direction; 
    int X=0;//
    cin >> N;
    
    int **matrix;
    matrix = new int*[N];//열
    for(int i=0;i<N;i++){
        matrix[i] = new int[N];//행
    }

    for(int j=0; j<N;j++)
    {
        for(int k=0; k<N;k++)
        {
            matrix[j][k] = 0;
        }
    }
    cin >> apple;//사과갯수.

    for(int a = 0; a<apple; a++)
    {
        cin >> row >> col;
        matrix[row][col] = 1;
    }
/////////////////////////////////////////////////여기까지 매트릭스 세팅.
////////////////////////////////////////////////이후부터 지렁이 moving
    cin >> mov;

    for(int i=0; i<mov; i++)
    {
        cin >> second >> direction;
        
    }

    cout << X <<endl;
    return 0;
}