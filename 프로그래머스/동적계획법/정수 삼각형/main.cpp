#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int answer;

int dp[501][501] = {
    0,
};

int recursive(int row, int col, vector<vector<int>> &a)
{
    cout << "row" << row << "col" << col << endl;
    if (a.size() == row)
        return 0;
    if (dp[row][col] > 0)
    {
        cout << "dp : "
             << "row" << row << "col" << col << endl;
        return dp[row][col];
    }

    return dp[row][col] = a[row][col] + max(recursive(row + 1, col, a), recursive(row + 1, col + 1, a));
}

int solution(vector<vector<int>> triangle)
{

    answer = -1;

    answer = recursive(0, 0, triangle);

    return answer;
}
