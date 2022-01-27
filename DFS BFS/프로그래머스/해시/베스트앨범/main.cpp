#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
//장르 랭크 정하기
//장르별 노래 랭크 정하기
//장르별 2개씩.

int cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int cmp1(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{

    vector<int> answer;

    map<string, int> genresRank;
    // gernres, plays.index, plays[i]
    map<string, map<int, int>> list;

    for (int i = 0; i < genres.size(); i++)
    {
        string genresName = genres[i];
        genresRank[genresName] += plays[i];
        list[genresName][i] = plays[i];
    }

    vector<pair<string, int>> Rank(genresRank.begin(), genresRank.end());

    sort(Rank.begin(), Rank.end(), cmp1);

    for (int i = 0; i < Rank.size(); i++)
    {
        string gName = Rank[i].first;

        vector<pair<int, int>> temp(list[gName].begin(), list[gName].end());
        sort(temp.begin(), temp.end(), cmp);

        if (temp.size() < 2)
        {
            answer.push_back(temp[0].first);
            continue;
            ;
        }
        else
        {
            for (int j = 0; j < 2; j++)
            {
                answer.push_back(temp[j].first);
            }
        }
    }

    return answer;
}
