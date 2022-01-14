#include <iostream>
#include<queue>
#include<string.h>
#define max 20

using namespace std;


int N;
int initMap[max][max];
bool visit[max][max];
int ans = 0;
void copyArr(int (*a)[max], int(*b)[max]);


void move(int dir, int (*map)[max]){

    switch (dir)
    {
    case 0://위
        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j < N; j++)
            {
                if (map[j][i] == 0)
                    continue;
                int temp = 0;
                while (1)
                {

                    if (map[j - 1-temp][i] == 0)
                    {
                        map[j - 1-temp][i] = map[j-temp][i];
                        map[j - temp][i] = 0;
                        temp++;
                        if(j-1-temp <= 0)
                            break;
                        continue;
                    }
                    
                    
                    else //다음칸이 0이 아님.
                    {
                        if (map[j - 1 - temp][i] == map[j - temp][i])
                        {
                            if (visit[j - 1-temp][i] == false)
                            {
                                map[j - 1-temp][i] = map[j - 1-temp][i] * 2;
                                map[j - temp][i] = 0;
                                visit[j - 1-temp][i] = true;
                                if (ans < map[j - 1-temp][i])
                                    ans = map[j - 1-temp][i];
                                break;
                            }
                            else
                                break;
                        }
                        else
                            break;
                    }
                }
            }
        }
        memset(visit, false, sizeof(visit));
        break;
    case 1: //왼
        for (int j = 0; j < N; j++)
        {
            for (int i = 1; i < N; i++)
            {

                if(map[j][i] == 0)
                    continue;
                    
                int temp = 0;
                while(1){
                    if(map[j][i-1-temp] == 0)
                    {
                        map[j][i - 1 - temp] = map[j][i - temp];
                        map[j][i - temp] = 0;
                        temp++;
                        if(i-1-temp < 0)//인덱스가 0보다 작아지면 break.
                            break;
                        continue;
                    }
                    else//다음칸이 0이 아님.
                    {
                        if (map[j][i - 1 - temp] == map[j][i - temp])
                        {
                            if (visit[j][i - 1 - temp] == false)
                            {
                                map[j][i - 1 - temp] = map[j][i - 1 - temp] * 2;
                                map[j][i - temp] = 0;
                                visit[j][i - 1 - temp] = true;
                                if (ans < map[j][i - 1 - temp])
                                    ans = map[j][i - 1 - temp];
                                break;
                            }
                            else
                                break;
                        }
                        else
                            break;
                    }
                }
            }
            
        }
        memset(visit, false, sizeof(visit));
        break;

    case 2://아 4 -> 3 2 1 0 
        for (int i = 0; i < N; i++)
        {
            for (int j = N-2; j >= 0; j--)
            {
                if(map[j][i] == 0)
                    continue;
                int temp = 0;
                while (1)
                {
                    if (map[j+1+temp][i] == 0)
                    {
                        map[j + 1 + temp][i] = map[j + temp][i];
                        map[j + temp][i] = 0;
                        temp++;
                        if(j+1+temp > N-1)
                            break;
                        continue;
                    }
                    else //다음칸이 0이 아님.
                    {
                        if (map[j + 1 + temp][i] == map[j + temp][i])
                        {
                            if (visit[j + 1 + temp][i] == false)
                            {
                                map[j + 1 + temp][i] = map[j + 1 + temp][i] * 2;
                                map[j + temp][i] = 0;
                                visit[j + 1 + temp][i] = true;
                                if (ans < map[j + 1 + temp][i])
                                    ans = map[j + 1 + temp][i];
                                break;
                            }
                            else
                                break;
                        }
                        else
                            break;
                    }
                }
            }
        }
        memset(visit, false, sizeof(visit));
        break;

    case 3://오
        for (int j = 0; j < N; j++)
        {
            for (int i = N-2; i >= 0; i--)
            {
                if (map[j][i] == 0)
                    continue;
                int temp = 0;
                while (1)
                {
                    if (map[j][i + 1 + temp] == 0)
                    {
                        map[j][i + 1 + temp] = map[j][i + temp];
                        map[j][i + temp] = 0;
                        temp++;
                        if(i+1+temp>N-1)
                            break;
                        continue;
                    }
                    else //다음칸이 0이 아님.
                    {
                        if (map[j][i + 1 + temp] == map[j][i + temp])
                        {
                            if (visit[j][i + 1 + temp] == false)
                            {
                                map[j][i + 1 + temp] = map[j][i + 1 + temp] * 2;
                                map[j][i + temp] = 0;
                                visit[j][i + 1 + temp] = true;
                                if (ans < map[j][i + 1 + temp])
                                    ans = map[j][i + 1 + temp];
                                break;
                            }
                            else
                                break;
                        }
                        else
                            break;
                    }
                }
            }
        }
        memset(visit, false, sizeof(visit));
        break;

    default:
        break;
    }

}



void dfs(int cnt, int (*m)[max]){

    
    if(cnt==5){
        return;
    }
    
    for (int i = 0; i < 4; i++) //위오아왼.
    {
        int temp[max][max] = {0, };
        copyArr(temp, m);
        move(i, temp);
        dfs(cnt+1, temp);
    }

    return;
}

void copyArr(int(*a)[20], int(*b)[20]){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            a[i][j] = b[i][j];
        }
    }
}

int main(){

    memset(initMap, 0, sizeof(initMap));
    memset(visit, false, sizeof(visit));

    cin >> N;

    
    for(int i = 0; i< N; i++){

        for(int j=0; j<N; j++){
            int a;
            cin >> a;
            initMap[i][j] = a;
            if(ans < a)
                ans = a;
        }
    }
    dfs(0, initMap);


    cout << ans;

    return 0;

}