#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iostream>

using namespace std;

// 3시 30분(180+30) ~ 4시 20분(240+20) = 50분(260-210)
// HH:MM
int calTime(string a, string b)
{
    int aiHH = stoi(a.substr(0,2));
    int aiMM = stoi(a.substr(3, 2));
    int biHH = stoi(b.substr(0,2));
    int biMM = stoi(b.substr(3,2));

    aiHH *= 60;
    biHH *= 60;

    int resultA = aiHH + aiMM;
    int resultB = biHH + biMM;

    return resultB - resultA;
}

//차량번호가 작은 자동차부터 청구할 주차 요금을 answer에 담는다.
//초과한시간 올림.
//초과한 시간 = 기본요금 + 알파.
//출차한 내욕 없으면 23:59분에 출차한것.
// fee 0 : 기본 시간, 1 : 기본 요금  2: 단위 시간 3: 단위 요금.
// records : "시각 차량번호 내역"string
//내역은 IN, OUT
vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;

    // string : 차번호 , vector에 입차,출차 입력.
    map<string, vector<string>> car;
    //차량번호저장.
    set<string> carNums;

    int basicTime = fees[0];
    int basicRate = fees[1];
    int unitTime = fees[2];
    int unitRate = fees[3];

    for (int i = 0; i < records.size(); i++)
    {
        istringstream ss(records[i]);
        string stringBuffer;

        vector<string> temp;
        while (getline(ss, stringBuffer, ' '))
        {
            temp.push_back(stringBuffer);
        }
        //차번호에 입차,출차입력.
        car[temp[1]].push_back(temp[0]);
        carNums.insert(temp[1]);
        temp.clear();
    }

    //시간별

    auto tm = carNums.begin();
    for (int i = 0; i < carNums.size(); i++)
    {

        string inTime = "";
        string outTime = "";
        int totalTime = 0;
        int cnt = 0;
        string carNum = *tm;
        tm++;

        for (auto c : car[carNum])
        {
            if (cnt % 2 == 0) //짝수면 인타임
                inTime = c;

            else //아웃타임.
            {
                outTime = c;
                totalTime += calTime(inTime, outTime);
            }
            cnt++;
        }
        if (cnt % 2 != 0)
        {
            outTime = "23:59";
            totalTime += calTime(inTime, outTime);
            cout << totalTime;
        }

        if (totalTime <= basicTime)
            answer.push_back(basicRate);
        else
        {
            totalTime -= basicTime;
            int price;
            //초과시간이 단위 시간으로 나누어 떨어지지 않으면.
            if (totalTime % unitTime != 0)
                price = ((totalTime / unitTime) + 1) * unitRate + basicRate;
            else
                price = (totalTime / unitTime) * unitRate + basicRate;
                
            answer.push_back(price);
        }
    }

    return answer;
}
