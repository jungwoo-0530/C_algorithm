#include <iostream>
#include <string.h>

using namespace std;

#define max 20
#define orderMax 1000
int N, M;//N 세로, M 가로
int x, y, k;
int map[max][max];
int order[orderMax];
int dice[6];
int diceDownIndex;
int diceUpIndex;
//현재 윗면, 동서남북(아랫면)
//1 : 3 4 2 5
//2 : 3 4 6 1
//3 : 1 6 5 2
//4 : 6 1 5 2
//5 : 3 4 1 6
//6 : 3 4 5 2
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

void changeDice(int a){

    int temp[6];
    copy(temp, dice);
    for(int i = 0; i<6; i++){
        dice[i] = temp[dir[a-1][i]-1];
    }

}



void solve(){
    diceDownIndex = 6;
    diceUpIndex = 1;//answer
    //ans = dice[diceUpIndex -1];
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