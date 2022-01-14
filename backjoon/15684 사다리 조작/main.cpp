#include <iostream>
#include <vector>

using namespace std;

// vector<vector<pair<bool, bool>>> line;



int N, M, H; //N 세로선 M 가로선 H 점선가로선.
int MIN = 9999;
bool map[10][30] = {false, };
//b, b+1 세로선을 a번째 점선 가로선 위치에 연결.

// bool trueAndFalse(vector<vector<pair<bool, bool>>> a)
// {
//     int curX=0; int curY=0;
//     int index = 0;
//     while(1){ 
//         //마지막줄.
//         if (curY == H-1)//마지막 점선가로줄.
//         {
//             if (a[curX][curY].first == true)
//             {
//                 if(index == --curX){
//                     index++;
//                     if (index == N) //마지막 세로줄.
//                         break;
//                     curX = index;
//                     curY = 0;
//                     continue;
//                 }
//                 else
//                     return false;
                
//             }

//             else if (a[curX][curY].second == true)
//             {
//                 if (index == ++curX)
//                 {
//                     index++;
//                     if(index == N)//마지막 세로줄.
//                         break;
//                     curX = index;
//                     curY = 0;
//                     continue;
//                 }
//                 else
//                     return false;
//             }
            
            
//             else{

//                 if (curX == index) //정상적으로 한줄이 된다면.
//                 {
//                     index++;
//                     if (index == N) //마지막 세로줄.
//                         break;
//                     curX = index;
//                     curY = 0;
//                     continue;
//                 }
//                 else
//                     break;
//             }

//         }

//         //마지막줄 x
//         if (a[curX][curY].second == true) //오른쪽에 선이 있으면
//         {
//             curX++;
//             curY++;
//             continue;
//         }
//         else if (a[curX][curY].first == true) //왼쪽에 선이 있으면.
//         {
//             curX--;
//             curY++;
//             continue;
//         }
//         else{
//             curY++;
//             continue;
//         }



//     }

//     if(index == N){
//         return true;
//     }

//     else
//         return false;
// }


// vector<vector<pair<bool, bool>>> copyVector(vector<vector<pair<bool, bool>>> a, vector<vector<pair<bool, bool>>>b)
// {
//     for (int i = 0; i < N; i++)
//     {
//         a.push_back(vector<pair<bool, bool>>());
//         for (int j = 0; j < H; j++)
//         {
//             a[i].push_back(b[i][j]);
//         }
//     }
//     return a;
// }

bool move(){
// [0][1]
// [0][0]
    //[x][y]
    int x = 0;
    int y = 0;

    for(int i=0; i < N; i++){
        x = i;
        y = 0;
        while(1){
            
            if(map[x][y] == true)//우.
            {
                x++;
                y++;
            }

            else if ((x != 0) && map[x][y] == false && map[x - 1][y] == true) //왼.
            {
                x--;
                y++;
            }
            else{
                y++;
            }

            if(y == H && i == x)
                break;

            else if(y == H && i != x)
                return false;
            
        }


    }
    return true;
}

// void dfs(int depth,vector<vector<pair<bool, bool>>> a, int x, int y)
// {

//     if(depth > 3 || MIN < depth){
//         return;
//     }

//     if (trueAndFalse(a) == true)
//     {
//         if (MIN > depth)
//         {
//             MIN = depth;
//             return;
//         }
//     }
//     if(depth == 3)
//         return;


    
//     ////줄을 추가하는 로직. 가로줄 추가는 무조건 오른쪽으로만 긋는다.
//     //1. 현재 위치세로줄에서 오른쪽 줄의 오른쪽에 줄이 없어야함.
//     //2. 현재 위치 세로줄에 줄이 없어야함.
//     //3. 오른쪽으로만 그으므로 첫번째 새로줄에서 왼쪽 검사는 하지말 것,
//     //3-1. 현재 세로줄에서 오른쪽 줄을 볼때 마지막 줄이면 마지막 줄에 오른쪽은 검사하지 말 것.
//     //4. 마지막줄은 하지 말것.
//     for(int i = x; i < N-1; i++){

//         for(int j = y; j<H; j++){

//             // y = 0;
//             // vector<vector<pair<bool, bool>>> temp;
//             // temp = copyVector(temp, a);
//             if (a[i + 1][j].second == true || a[i][j].first == true || a[i][j].second == true)
//                 continue;

//             a[i][j].second = true;
//             a[i+1][j].first = true;

//                 dfs(depth + 1, a, i, j+1);
            

//             a[i][j].second = false;
//             a[i + 1][j].first = false;
            
//         }

//         y = 1;

//     }   
    
// }

void dfsArray(int depth, int x, int y)//1 0 2
{
    if (depth > 3 || MIN < depth)
    {
        return;
    }

    if (move() == true)
    {
        if (MIN > depth)
        {
            MIN = depth;
            return;
        }
    }
    if (depth == 3)
        return;

    for (int i = x; i < N - 1; i++)
    {

        for (int j = y; j < H; j++)
        {

            //현재 위치에서 다음 세로선에 선이 있으면
            //현재 위치에 선이 있으면
            //첫번째 세로선이 아니고 현재 위치에서 전 위치 세로선에 선이 있으면
            //선 생성 x. 스킵.
            if (map[i + 1][j] == true || map[i][j] == true || ( (i != 0) && map[i-1][j] == true))
                continue;


            map[i][j] = true;

            dfsArray(depth + 1, i, j + 1);

            map[i][j] = false;
        }
        y = 0;
    }
}

int main()
{

    cin >> N >> M >> H;


    for(int i=0; i < M; i++){
        int a, b;
        cin >> a >> b;
        map[b-1][a-1]=true;
    }




    // for(int i = 0; i < N; i++){
    //     line.push_back(vector<pair<bool, bool>>());
    //     for(int j = 0; j < H; j++){
    //         line[i].push_back(make_pair(false, false));
    //     }
    // }


    // for(int i = 0; i < M; i++){
    //     int a, b;
    //     cin >> a >> b;
        
    //     line[b-1][a-1].second = true;
    //     line[b][a-1].first = true;
    // }

    // for(int i = 0; i<N; i++){
    
    //     for(int j = 0; j<H; j++){
    //         cout << line[i][j].first << line[i][j].second << "||";
    //     }
    //     cout << endl;
    // }

    // cout << trueAndFalse(line);


    // dfs(0, line, 0, 0);

    dfsArray(0,0,0);

    if(MIN > 3 || MIN == 9999)
    {
        cout << "-1";
        return 0;
    }
    cout << MIN;

    
    return 0;
}