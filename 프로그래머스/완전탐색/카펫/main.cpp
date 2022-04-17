#include <string>
#include <vector>

using namespace std;

//가로 세로 리턴.
// b 가로길이 4 -> y 가로길이 4-2 = 2 -> yCol = bCol-2
// b 세로길이 3 -> y 세로길이 3-2 = 1 -> yRow = bRow-2
int a;
int b;

void solve(int bRow, int bCol, int y)
{

    if (bRow * bCol == y)
    {
        //이러면 끝. bRow+2, bCol+2이
        a = bCol + 2;
        b = bRow + 2;
        return;
    }

    bRow = bRow + 1;
    bCol = bCol - 1;
    solve(bRow, bCol, y);
}

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    int bRow = 1;
    int bCol = 1;

    bCol = (brown - 6) / 2;

    if (brown == 4)
    {
        answer.push_back(2);
        answer.push_back(2);
        return answer;
    }

    solve(bRow, bCol, yellow);

    answer.push_back(a);
    answer.push_back(b);

    return answer;
}
