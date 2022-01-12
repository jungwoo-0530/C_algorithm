#include <string>
#include <vector>
#include<iostream>
#include<stdlib.h>

using namespace std;

vector<string>Operator;
vector<string>token;

void find_operator(string expression)
{
    string temp;
    for(int i = 0; i<expression.size(); i++)
    {
        cout << expression[i];
        char a[1];
        a[0] = expression[i];
        if(a[0] == '-' || a[0] == '+' || a[0] == '*')
        {
            token.push_back(temp);
            string str1(a);
            token.push_back(str1);
            Operator.push_back(a);
            temp.clear();
        }
        else
            temp += a;
        
    }
    for(int i = 0; i<Operator.size(); i++)
    {
        cout << Operator[i] << endl;
    }
    Operator.erase(unique(Operator.begin(), Operator.end()), Operator.end());
    for(int i = 0; i < token.size(); i++)
    {
        cout << token[i]<<endl;
    }

}

void dfs(char operator_, int depth)
{
    if(Operator.size() == depth)
    {

    }

    for(int i = 0; i < token.size(); i++)
    {
        if(token[i] == )
    }

}

long long solution(string expression)
{
    long long answer = 0;

    find_operator(expression);

    for(int i = 0; i < Operator.size(); i++)
    {
        //dfs(Operator[i], 0);
    }

    return answer;
}

int main()
{
    string a = "100-200*300-500+20";
    string b = "100";
    string c = "200";
    int num1;
    num1 = atoi(b.c_str());
    int num2 = atoi(c.c_str());
    cout << num1+num2;
    solution(a);

    return 0;
}