#include <string>
#include <vector>

using namespace std;

bool visit[20] = {false,};
int cnt = 0;
void dfs(vector<int>num, int ans, int target)
{
    if(target == ans){
        cnt++;
        return;
    }

    for(int i = 0; i<num.size(); i++)
    {

        if(visit[i] == true)
            continue;
        dfs(num, ans+num[i], target);
        dfs(num, ans-num[i], target);
    }
}


int solution(vector<int> numbers, int target)
{
    int answer = 0;

    dfs(numbers, 0, target);

    cout << cnt;

    return answer;
}