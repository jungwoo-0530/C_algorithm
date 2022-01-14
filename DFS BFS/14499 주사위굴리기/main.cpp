#include <iostream>
#include <string.h>

using namespace std;

#define max 20
#define orderMax 1000
int N, M;//N 세로, M 가로
int x, y, k;
int map[max][max]; // 4*20*20 = 800byte.
int order[orderMax];
int dice[6];

//[4] = 4방향 [6] = 인덱스 면에 따라 어떤 면이 오는지.
// [0][0] = 1번 방향으로 이동, 1번 면에 어떤 면이 오는지.
int dir[4][6] = {
    {4, 2, 1, 6, 5, 3},
    {3, 2, 6, 1, 5, 4},
    {5, 1, 3, 4, 6, 2},
    {2, 6, 3, 4, 1, 5}
};

void copy(int a[6], int b[6]){
    for(int i = 0; i<6; i++){
        a[i] = b[i];
    }
}

// a 는 이동 방향. 이동 방향대로 움직일 때,
//어떤 면이 어디로 가는지 dice에 재입력.
void changeDice(int a)
{

    int temp[6];
    copy(temp, dice);
    for(int i = 0; i<6; i++){
        dice[i] = temp[dir[a-1][i]-1];
    }

}



void solve(){
    for(int i=0; i<k; i++){

        if(order[i] == 1)//동
        {
            if(y + 1 > M-1)
                continue;
            y = y + 1;
        }
        else if(order[i] == 2)//서
        {
            if(y - 1 < 0)
                continue;
            y = y - 1;
        }
        else if(order[i] == 3)//북
        {
            if(x - 1 < 0)
                continue;
            x = x - 1;
        }
        else//남
        {
            if(x + 1 > N-1)
                continue;
            x = x + 1;
        }
        
        changeDice(order[i]);

        if (map[x][y] == 0)
        {
            map[x][y] = dice[5];
            cout << dice[0] << endl;
        }

        else
        {
            dice[5] = map[x][y];
            map[x][y] = 0;
            cout << dice[0]<<endl;
        }
        
    }


}


int main(){

    cin >> N >> M >> x >> y >> k;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i<k; i++){
        cin >> order[i];
    }

    memset(dice, 0, sizeof(dice));

    solve();

    return 0;
}