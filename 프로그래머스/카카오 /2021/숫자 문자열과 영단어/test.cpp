#include<string>
#include<iostream>

using namespace std;


int main(){

    string s = "1234";

    s = s.substr(0);
    int strSize = s.size();

    cout << s << endl;
    cout << strSize << endl;


    string a = "1234";
    char b = '5';

    a += b;

    cout << a;
    

    return 0;
}