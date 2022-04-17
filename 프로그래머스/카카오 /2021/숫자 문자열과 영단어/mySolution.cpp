#include <string>
#include <vector>
#include <iostream>

using namespace std;

//첫번째 값, 두번째 크기
pair<int, int> findString(string a){

    if(a[0] == 'z'){
        return make_pair(0, 4);
    }
    else if(a[0] == 'o'){
        return make_pair(1, 3);
    }
    else if(a[0] == 't'){
        if(a[1] == 'w'){
            return make_pair(2, 3);
        }
        else{
            return make_pair(3, 5);
        }
    }
    else if(a[0] == 'f'){
        if(a[1] == 'o'){
            return make_pair(4, 4);
        }
        else{
            return make_pair(5, 4);
        }
    }
    else if(a[0] == 's'){
        if(a[1] == 'i'){
            return make_pair(6, 3);
        }
        else{
            return make_pair(7, 5);
        }
    }
    else if(a[0] == 'e'){
        return make_pair(8, 5);
    }
    else if(a[0] == 'n')//nine
    {
        return make_pair(9, 4);
    }
    else{//숫자
        return make_pair(0,0);
    }
}
//oneseven
//cur = 3 s temp 1
//size 3
//1 
int solution(string originalStr) {
    int answer = 0;
    string temp;
    int cur = 0;
    string s = originalStr;
    while(originalStr.size() > cur){
        pair<int, int> pairTemp;

        s = originalStr.substr(cur);
        cout << s << endl;
        cout << "cur" << cur << endl;

        pairTemp = findString(s);

        if(pairTemp.second == 0){//현재 cur가 숫자이면.
            // temp += to_string()
            cur += 1;
            temp += s[0];
            cout << "debug" << s[0] << endl;
            // s = s.substr(cur);
            continue;
        }

        cur += pairTemp.second;
        temp += to_string(pairTemp.first);
        // if(originalStr.size() < cur){
        //     break;
        // }
        

    }
    
    answer = stoi(temp);
    return answer;
}


int main(){

    string a = "one4seveneight";
    string b = "oneseven";
    string c = "123";

    cout << solution(a);

    return 0;
}