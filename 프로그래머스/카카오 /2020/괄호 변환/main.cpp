#include <string>
#include <vector>

#include<iostream>

using namespace std;


bool check(string p){
    int cnt = 0;
    for(int i = 0; i<p.size(); i++)
    {

        if(p[i] == '(')
            cnt++;
        else{
            if(!cnt)
                return false;
            cnt--;
        }

    }
    return true;
}


string solve(string p)
{
    int Lcnt= 0;
    int Rcnt = 0;//L ( R )   
    string u, v;

    if(p == "")
        return p;

    for (int i = 0; i < p.length(); i++)
    {
        if(p[i] == '(')
            Lcnt++;
        
        else
            Rcnt++;
        if(Lcnt == Rcnt)
        {
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    if(check(u))
        return u+solve(v);
    else{
        string temp = "(";
        temp += solve(v) + ")";
        u = u.substr(1, u.length()-2);
        for (int i = 0; i < u.length(); i++)
        {
            if(u[i] == '('){
                temp += ')';
            }
            else{
                temp += '(';
            }
        }
        return temp;
    }

}

string solution(string p)
{
    string answer = "";

    if(check(p))
        return p;
    answer = solve(p);

    return answer;
}

int main(){
    string a = ")(";
    cout << solution(a);
    return 0;
}