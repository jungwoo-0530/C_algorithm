#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

// x(가로) y(세로) a(0 기둥 1 보) b(0삭제, 1설치)

bool oneCheck(const set<vector<int>> &building, vector<int> pred)
{
    if (building.find(pred) != building.end())
        return true;
    return false;
}

bool check(const set<vector<int>> &building)
{
    for (auto build : building)
    {
        int x = build[0];
        int y = build[1];
        int a = build[2];

        if (a == 0)
        {
            vector<int> pred[3] = {{x, y - 1, 0}, {x, y, 1}, {x - 1, y, 1}};
            if (y == 0 || oneCheck(building, pred[0]) || oneCheck(building, pred[1]) || oneCheck(building, pred[2]))
                continue;
            return false;
        }
        else
        {
            vector<int> pred[4] = {{x, y - 1, 0}, {x + 1, y - 1, 0}, {x + 1, y, 1}, {x - 1, y, 1}};
            if (oneCheck(building, pred[0]) || oneCheck(building, pred[1]) || (oneCheck(building, pred[2]) && oneCheck(building, pred[3])))
                continue;
            return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;
    set<vector<int>> building;

    for (int i = 0; i < build_frame.size(); i++)
    {
        vector<int> v = {build_frame[i][0], build_frame[i][1], build_frame[i][2]};
        if (build_frame[i][3] == 0) //삭제
        {
            building.erase(v);
            if (!check(building))
                building.insert(v);
        }

        else
        {
            building.insert(v);
            if (!check(building))
                building.erase(v);
        }
    }

    for (auto build : building)
    {
        answer.push_back(build);
    }

    return answer;
}

int main()
{

    vector<int> a{1, 0, 0, 1};
    vector<int> b{1, 1, 1, 1};
    vector<int> c{2, 1, 0, 1};
    vector<int> d{2, 2, 1, 1};
    vector<int> e{5, 0, 0, 1};
    vector<int> f{5, 1, 0, 1};
    vector<int> g{4, 2, 1, 1};
    vector<int> q{3, 2, 1, 1};

    vector<vector<int>> temp;
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(c);
    temp.push_back(d);
    temp.push_back(e);
    temp.push_back(f);
    temp.push_back(g);
    temp.push_back(q);

    vector<vector<int>> z;
    z = solution(8, temp);

    //    a = solution(6, a);

    return 0;
}