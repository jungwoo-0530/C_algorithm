#include <iostream>

using namespace std;
//nCr
//4C2 4*3 / 2*1
void Combination(int r)
{
    //r = 2
    int n = 3;
    int ans = 0;
    int temp = 1;
    for(int i = 0; i < r; i++)
    {
        //i 4, 3 
        temp *= n--;   
    }
    cout << temp;
    for(int i = 0; i < r; i++)
    {
        temp /= r--;
    }
    cout << temp;

}

int main()
{
//     int count_ = 0;
//     int cnt = 2;
//     for (int i = 1; i < 3; i++)
//         count_ += count(i);

//     cout << count_;
    Combination(2);
    return 0;
}