#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        auto start = array.begin() + commands[i][0] - 1;
        auto end = array.begin() + commands[i][1];

        vector<int> temp(start, end);

        sort(temp.begin(), temp.end(), less<>());

        answer.push_back(temp[commands[i][2] - 1]);
    }

    return answer;
}
