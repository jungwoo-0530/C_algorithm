#include <string>
#include <vector>
#include <map>

using namespace std;

void dfs(int index, int depth, string order, string temp, int d){

    if(c.size() == d)
    {

    }


    for(int i = index; i < order.size(); i++){
        temp[depth] = order[i];

        dfs(i+1, depth+1, order, temp, d);
    }

}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;


    for(int i = 0; i < course.size(); i++)
    {   map<string, int> temp;
        for(int j = 0; j < orders.size(); j++)
        {
            dfs(orders[j], course[i], temp, "");
        }
    }

    


    

    return answer;
}