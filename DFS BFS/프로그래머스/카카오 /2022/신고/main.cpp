#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

// map으로 나온 이름마다 +1
// k임계값 넘지 못하는 것들 map에서 삭제.
// for문에서 report돌면서 answer벡터에 map에 있는 값들 넣기.

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer(id_list.size(), 0);

    map<string, set<string>> a;
    map<string, int> countMap;
    // a에 map<신고자, 신고목록>>a에 저장함(중복제거해서)
    for (int i = 0; i < report.size(); i++)
    {

        string target;
        string name;

        istringstream ss(report[i]);
        string stringBuffer;
        int cnt = 0;
        while (getline(ss, stringBuffer, ' '))
        {
            cnt++;
            if (cnt == 1)
                name = stringBuffer;
            else
            {
                target = stringBuffer;
                //신고당한사람 카운트.
                countMap[target]++;
            }
        }
        // insert 중복시 return pair<iterater
        auto flag = a[name].insert(target);
        //신고자와 신고당한 사람 중복일시, 카운트가 올라가지 않으므로.
        if (flag.second == false)
            countMap[target]--;
    }

    // answer에 id_list순으로
    for (int i = 0; i < id_list.size(); i++)
    {
        //신고자
        string name = id_list[i];
        //신고자별 신고당한사람.

        //신고당한사람
        for (auto iter : a[name])
        {
            string target = iter;
            // countMap[target] 이름별 신고당한 횟수.
            if (countMap[target] >= k)
                answer[i] = answer[i] + 1;
        }
    }

    return answer;
}
