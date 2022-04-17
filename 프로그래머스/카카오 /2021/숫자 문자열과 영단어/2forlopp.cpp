#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(string s) {
    int answer = 0;

    string strAns;

    string num_str[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int cur = 0;
    int cnt = 0;
    while(s.size() > cur){

        if(s[cur] >= '0' && s[cur] <= '9'){
            strAns += s[cur];
            cur += 1;
        }
        else{
            for(int i = 0; i<10; i++){
                string temp = s.substr(cur, num_str[i].size());

                if(num_str[i] == temp){
                    strAns += to_string(i);
                    cur += num_str[i].size();
                    break;
                }
            }
            
        }
        cout << cur << endl;
    }
    
    answer = stoi(strAns);

    return answer;
}


int main(){

    string a = "one4seveneight";
    string b = "oneseven";
    string c = "123";

    cout << solution(b);

    return 0;
}