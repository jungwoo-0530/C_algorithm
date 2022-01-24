#include<string.h>
#include<iostream>

using namespace std;



int main()
{

    string a;
    a.resize(2);
    cout << a.size();
    cout << a.length();
    a = "abc";
    // a += "a";
    // a += "b";
    // a += "c";
    cout << a.size();
    cout << a.length();
    // for(int i = 0; i<3; i++)
    // {
    //     a = a + "a";
    // }

    for(int i = 0; i<4; i++)
    {
        cout << a[i];
    }


    return 0;
}