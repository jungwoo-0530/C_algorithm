#include <string>
#include <vector>

using namespace std;
// skill = [type(1:공격, 2:회복), r1, c1, r2, c2, degree(수치)]
int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;

    int row = board.size();
    int col = board[0].size();

    int map[100][100] = {
        0,
    };

    for (int i = 0; i < skill.size(); i++)
    {

        int r1 = skill[i][1];
        int r2 = skill[i][3];
        int c1 = skill[i][2];
        int c2 = skill[i][4];

        int degree = skill[i][5];
        if (skill[i][0] == 1)
            degree = -degree;

        map[r1][c1] += degree;
        map[r2 + 1][c2 + 1] += degree;

        map[r1][c2 + 1] -= degree;
        map[r2 + 1][c1] -= degree;
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            map[i][j] = map[i][j] + map[i - 1][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            map[i][j] = map[i][j] + map[i][j - 1];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            map[i][j] += board[i][j];
            if (map[i][j] > 0)
                answer++;
        }
    }

    return answer;
}
