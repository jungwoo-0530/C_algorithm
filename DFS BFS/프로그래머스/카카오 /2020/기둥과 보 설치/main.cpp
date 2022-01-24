#include <string>
#include <vector>
#include <iostream>

using namespace std;

//x(가로) y(세로) a(0 기둥 1 보) b(0삭제, 1설치)
vector<vector<int> > solution(int n, vector<vector<int> > build_frame1)
{
    vector<vector<int> > answer(7, vector<int>(3, 0));
    answer.clear();
    //first 기둥, second 보.
    vector<vector<pair<bool,bool> > > map;
    vector<vector<int> > build_frame(6, vector<int>(4,0));
    
    build_frame[0][0]= 1;
    build_frame[0][1]= 0;
    build_frame[0][2]= 0;
    build_frame[0][3]= 1;

    build_frame[1][0] = 1;
    build_frame[1][1] = 1;
    build_frame[1][2] = 1;
    build_frame[1][3] = 1;

    build_frame[2][0] = 1;
    build_frame[2][1] = 1;
    build_frame[2][2] = 1;
    build_frame[2][3] = 1;

    build_frame[3][0] = 2;
    build_frame[3][1] = 1;
    build_frame[3][2] = 1;
    build_frame[3][3] = 1;

    build_frame[4][0] = 3;
    build_frame[4][1] = 1;
    build_frame[4][2] = 1;
    build_frame[4][3] = 1;

    build_frame[5][0] = 4;
    build_frame[5][1] = 0;
    build_frame[5][2] = 0;
    build_frame[5][3] = 1;

    cout << build_frame[0][3];
    cout << build_frame[5][0];
    cout << build_frame.size();
    for(int i = 0; i < 3; i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];

        if(build_frame[i][3] == 1)//설치
        {
            if (build_frame[i][2] == 0)//기둥
            {
                if((y == 0) || (map[y][x-1].second == true) || map[y-1][x].first == true)
                {   
                    answer[i].push_back(x);
                    answer[i].push_back(y);
                    answer[i].push_back(build_frame[i][2]);
                }
            }
            else//보
            {
                if(map[y-1][x-1].first == true || (map[y][x-1].second == true && map[y][x+1].second == true)){
                    answer[i].push_back(x);
                    answer[i].push_back(y);
                    answer[i].push_back(build_frame[i][2]);
                }
            }
        }

        else//삭제
        {
            if (build_frame[i][2] == 0) //기둥
            {
            }
            else //보
            {
            }
        }
    }
    cout << endl;
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i][0] << " " << answer[i][1] << " " << answer[i][2] << endl;
    }


    return answer;
}

int main()
{
    vector<vector<int> > a;
    a = solution(6, a);

    return 0;
}