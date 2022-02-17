#include <iostream>
#include <string>
#include <vector>
#include<map>

// //1234 -> 123 124 234 
// // 1234 -> 12 13 14 23 24 34
using namespace std;

// string ans= "";


// void dfs(int depth, string x, string number, int index, int k)// dfs 시간초과.
// {

//     if(depth == number.size()-k)
//     {
//         if(ans < x)
//         {
//             ans = x;
//             return;
//         }
//         return;
//     }

//     for (int i = index; i < number.size(); i++)
//     {
//         dfs(depth + 1, x+number[i] , number, i+1, k);
//     }
// }

string solution(string number, int k)
{
    string answer = "";

    int maxIdx = 0;
    int start = 0;
    char max = ' ';
    //number에서 빼야되는 숫자가 k -> number.size()-k갯수
    for (int i = 0; i < number.size() - k; i++)
    {

        max = number[start];
        maxIdx = start;
        //숫자 중 큰 수는 앞에 숫자가 제일 큰 수가 가장 큰수.
        for (int j = start; j <= i + k; j++)
        {
            if (number[j] > max)
            {
                maxIdx = j;
                max = number[j];
            }
        }
        answer += max;
        start = maxIdx + 1;
    }

    return answer;
}

int main(){
     string num;
     // int k;

     cin >> num >> k;

     dfs(0, "", num, 0);

     cout << ans;

     map<string, string>a;
     


     return 0;
 }