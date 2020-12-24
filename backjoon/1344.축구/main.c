#include<stdio.h>


double probability(int a, int b)
{
    int Ascore = 0;
    int Bsocre = 0;
    int denominator = 0;//모든 경우의 수.
    double A_pro = a/100;
    double B_pro = b/100;


    //경우의 수를 구하여라. 몇번의 경우의 수가 생기냐.
    // 소수/모든 경우의 수. 소수는 18이하 소수는 총 7개. A가 소수이든 B가 소수이든.
    //모든 경우의 수 : 3^18
    for(int i = 0; i<18; i++)//90분 5분간격 18번.
    {
        denominator *= 3;

    }

    /////////////////////////////
    // 이제 여기서부터 분자를 구해야하는 곳.

        

}


int main()
{
    int a = 0;//a팀 골 넣을 확률
    int b = 0;//b팀 골 넣을 확률

    scnaf("%d",&a);
    scanf("%d",&b);

    printf("%f\n", probability(a,b));


}