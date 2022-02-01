#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

// dp[1] = 5
// dp[2] = 55, 5+5, 5-5, 5*5, 5/5
// dp[3] = 555, 55+5, 55-5, 5-55, 5+55, 55*5, 55/5, 5*5*5, 5/5*5, 5/5/5, 5*55..

int addNum(int N, int idx)
{
    int result = N;
    for (int i = 1; i <= idx; i++)
    {
        result = result * 10 + N;
    }

    return result;
}

int solution(int N, int number)
{
    if (N == number)
        return 1;

    vector<unordered_set<int>> dp(8);
    dp[0].insert(N);

    for (int i = 1; i < 8; i++)
    {

        dp[i].insert(addNum(N, i));

        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < i; k++)
            {
                if (j + k + 1 != i)
                    continue;

                for (auto h : dp[j])
                {
                    for (auto z : dp[k])
                    {
                        dp[i].insert(h + z);

                        if (h - z > 0)
                            dp[i].insert(h - z);

                        dp[i].insert(h * z);

                        if (h / z > 0)
                            dp[i].insert(h / z);
                    }
                }
            }
        }

        if (dp[i].find(number) != dp[i].end())
        {
            return i + 1;
        }
    }

    return -1;
}
