#include<iostream>

using namespace std;

int main()
{
    int kg = 0;
    int count = 0;

    cin >> kg;

 

    if(kg > 5000 || kg < 3)
    {
        return -1;
    }

    while(1)
    {
        if(kg%5 == 0)
        {
            count += kg/5;
            break;
        }
        
        kg -= 3;
        count++;
        
        if(kg<0)
        { printf("-1\n");
            return 0;
        }
    }


    printf("%d\n",count);
    return 0;
}