#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

vector<pair<int,int>>R;
vector<pair<int,int>>L;
vector<pair<int,int>>NUM;
string dist(int num_row, int num_col, string hand)
{
    int R_dist = abs(R[0].first - num_row) + abs(R[0].second - num_col);
    int L_dist = abs(L[0].first - num_row) + abs(L[0].second - num_col);

    if(R_dist > L_dist)
    {
        L[0].first = num_row;
        L[0].second = num_col;
        return "L";
    }
    else if (L_dist > R_dist)
    {
        R[0].first = num_row;
        R[0].second = num_col;
        return "R";
    }
    else
    {
        if(hand == "right")
        {
            R[0].first = num_row;
            R[0].second = num_col;
            return "R";
        }
        else{
            L[0].first = num_row;
            L[0].second = num_col;
            return "L";
        }
    }

}
string solution(vector<int> numbers, string hand)
{
    string answer = "";
    NUM.push_back(make_pair(3,1));
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            NUM.push_back(make_pair(i,j));
        }
    }
    
    R.push_back(make_pair(3,2));
    L.push_back(make_pair(3,0));

    for(int i = 0; i<numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            L[0].first = NUM[numbers[i]].first;
            L[0].second = NUM[numbers[i]].second;
            answer += "L";
        }

        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            R[0].first = NUM[numbers[i]].first;
            R[0].second = NUM[numbers[i]].second;
            answer += "R";
        }

        else
            answer += dist(NUM[numbers[i]].first, NUM[numbers[i]].second, hand);
    }
    cout << answer;
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(8);
    a.push_back(2);
    a.push_back(1);
    a.push_back(4);
    a.push_back(5);
    a.push_back(9);
    a.push_back(5);
    string b = "right";
    solution(a, b);
    return 0;
}