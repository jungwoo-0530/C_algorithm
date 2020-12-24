#include<stdio.h>
// 준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
// 동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

void bubble_sort(int list[], int n){
    int i, j, temp;

    for(i=n-1; i>0; i--){
        // 0 ~ (i-1)까지 반복
        for(j=0; j<i; j++){
            //j번째 j+1번째의 요소가 크기 순이 아니면 교환
            if(list[j]<list[j+1]){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}


int main()
{
    int value = 0;//채울 총 값
    int coin_type=0;//동전 종류
    int coin_count = 0;
    scanf("%d %d",&coin_type, &value);

    int coin[coin_type];//동전 종류별 값어치

    for(int i = 0; i<coin_type; i++)
    {
        scanf("%d", &coin[i]);
    }

    bubble_sort(coin, coin_type);
    
    for(int j = 0; j<coin_type; j++)
    {
        while(1)
        {
            if(value<coin[j])
            {
                break;
            }

            else
            {
                value -= coin[j];
                coin_count++;
            }
            
        }

    }

    printf("%d\n",coin_count);


    return 0;
}