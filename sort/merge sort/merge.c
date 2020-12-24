#include<stdio.h>
///////////////////////////////////////////////////////////////////////////
// 합병 단계를 3단계
// 1. 분할 : 입력배열 2개로 나눈다.
// 2. 정복 : 순환 호출로 다시 분할 정복방법 사용
// 3. 결합 : 정렬된 배열들을 하나로 합친다.


void merge(int list[], int n)
{


}


 void mergesort(int list[],int sort[] , int n, int m)
{




}

int main()
{   int n = 0;
    int m = 4;
    int list[8] = {21, 10, 12, 20, 25, 13, 15, 22};
    int sorted_list[8];

    merge(list, 8);

    for(int i = 0; i<8; i++)
    {
        printf("%d\n",list[i]);
    }

    return 0;
}