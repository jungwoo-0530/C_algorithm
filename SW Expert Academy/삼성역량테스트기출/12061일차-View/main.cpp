#include <iostream>
#include <algorithm>
#define MAX 1001

//맨왼쪽, 맨오른쪽 두칸에는 건물이 지어지지 않는다.
//각 빌딩의 높이의 최대는 255
using namespace std;

int T;
int building[MAX];
int answer;
//현재 위치에서 왼쪽 두칸 오른쪽 두칸 빌딩의 값을 비교
//비교할때 필요한 조건 : 1. 현재 위치에서 크면 스킵 2. 현재 위치보다 작으면 뺀 값을 저장.
//3.  
int finder(int point)
{
    bool flag = false;
    int right = 0;
    int right_high = 0;
    int left = 0;
    int left_high = 0;

    if(building[point+1] < building[point + 2])
        right_high = building[point+2];
    else
        right_high = building[point+1];

    if (building[point - 1] < building[point - 2])
        left_high = building[point - 2];
    else
        left_high = building[point - 1];

    if(building[point] < right_high || building[point] < left_high)
        return 0;

    if(right_high < left_high)
        return building[point] - left_high;
    else
        return building[point] - right_high;


}

void solve()
{
    for(int j = 0; j<10; j++)
    {
        cin >> T;
        answer = 0;
        memset(building, 0, sizeof(building));
        for(int i=0; i<T; i++)
        {
            cin >> building[i];
        }
        
        for(int i = 0; i<T; i++)
        {
            if(i == 0 || i == 1 || i == T-1 || i == T-2)
                continue;
            answer += finder(i);
        }

        cout << "#" << j+1 << " " << answer << endl;
    }

    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}