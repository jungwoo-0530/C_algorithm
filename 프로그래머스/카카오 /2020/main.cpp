#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(string s)
{
    
    int answer = 0;

    int maxCut = s.size()/2; //s문자열의 최대단위 자르기. 10글자면 5단위씩 커트.

    for(int i = maxCut; i > 0; i--) // 5, 4, 3, 2, 1
    {
        vector<string> a;
        int start = 0;

        for(int j = start; j < s.size(); j++)
        {
            string temp;
            int cnt = 1;
            bool flag = false;
            while(1)
            {
                string home = s.substr(start, start+maxCut-1);
                string next = s.substr(start + maxCut, start + 2*maxCut - 1);

                if(home == next)
                {
                    cnt++;
                    start = start + maxCut;
                    flag = true;
                    continue;
                }
                else if(home != next && cnt == 1)
                {
                    start += 1;
                    string one = s.substr(start, start);
                    a.push_back(one);
                    break;
                }
                else{

                    temp = to_string(cnt) + temp;
                    a.push_back(temp);
                    start = start + maxCut - 1;
                    break;
                }
            }   
        
        }
        int min = -1;
        for (int i = 0; i < a.size(); i++)
        {
            min += a[i].size();
        }
        if(answer > min)
        {
            answer = min;
        }

    }

    


    return answer;
}

int main(){

    string s = "abcabcdede";
    int answer = s.size();
    for(int i = 1; i <= s.size()/2; i++ )
    {
        string result = "";
        string str = s.substr(0, i);
        int cnt = 1;
        for (int j = i; j <= s.size() ; j+=i)
        {   
            if(str == s.substr(j, i))
            {
                cnt ++;
            }
            else{
                if(cnt == 1)
                {
                    result += str;
                }
                else{
                    result += (to_string(cnt) + str);
                }

                str = s.substr(j, i);
                cnt = 1;
            }
            
        }

        if((s.size())%i != 0){
            result += s.substr((s.size()/i)*i);
        }
        cout << result << endl;
        if (answer > result.size())
            answer = result.size();
    }
    cout << answer;
    // solution(str);

}