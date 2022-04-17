//https://programmers.co.kr/learn/courses/30/lessons/77484
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int cnt = 0;
    int zerocnt = 0;
    int wrongNum = 0;

    for(auto i : lottos){
        if(i == 0){
            zerocnt++;
        }
    }

    for(auto i : win_nums){

        for(int j : lottos){
            
            if(i == j){
                cnt ++;
                break;
            }
        }
    }
    //안맞는 숫자가 zero 혹은 틀린 번호
    //zero가 최고 최저를 결정. zero cnt만큼 로또 순위를 +-

    int cntRank = 7-cnt; // 전부 다 틀린경우를 생각해야함.

    //////////////zero

    int highRank = cntRank - zerocnt;
    int lowRank = cntRank;

    
    if(highRank < 1){
        highRank = 1;
    }
    if(lowRank > 5){
        lowRank = 6;
    }
    if(highRank > 5)//최고 순위인데 아무것도 안맞을 경우.
    {
        highRank = 6;
    }

    answer.push_back(highRank);
    answer.push_back(lowRank);

    return answer;
}

int main(){

    vector<int>lottos = {44, 1, 0, 0, 31, 25};
    vector<int>win_nums = {31, 10, 45, 1, 6, 19};

    // vector<int>lottos = {44, 1, 0, 0, 31, 25};
    // vector<int>win_nums = {31, 10, 45, 1, 6, 19};

    for(auto i : solution(lottos, win_nums)){

        cout << i << endl;

    }

    return 0;
}