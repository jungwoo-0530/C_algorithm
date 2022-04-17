#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string a, string b)
{
    string temp = "";
    temp += a + b;

    string temp1 = "";
    temp1 += b + a;

    if (temp > temp1)
    {
        return true;
    }

    else if (temp1 > temp)
    {
        return false;
    }

    else
        return false;
}

string solution(vector<int> numbers)
{
    string answer = "";

    vector<string> strNumbers;

    for (int i = 0; i < numbers.size(); i++)
    {
        string temp = "";
        temp = to_string(numbers[i]);
        strNumbers.push_back(temp);
    }

    sort(strNumbers.begin(), strNumbers.end(), cmp);

    for (auto a : strNumbers)
    {
        answer += a;
    }

    if (answer.size() == count(answer.begin(), answer.end(), '0'))
        return "0";

    

    return answer;
}
