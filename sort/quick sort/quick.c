//quick sort
//기준키 기준으로 작거나 같은 값은 앞으로 큰 값은 뒤로.
//기준키 맨앞, 맨뒤 두개. 맨앞 기준키보다 큰값과 맨뒤보다 작은 값을 선택후 교체.

#include<stdio.h>
// 우선 순차적으로 기준키보다 작고 큰값을 찾는다.

void quicksort(int list[], int left, int right)
{
    int i = left+1;
    int j = right-1;
    int temp;
        while(1)
        {
            while(1)
            {
                if(list[left]<list[i])
                    break;
                i++;
                if(i == right)
                 break;
            }
            while(1)
            {
                if(list[right]>list[j])
                    break;   
                j--;
                if(j == left)
                    break;
            }
            if (i>j)
            {
                temp = list[left];
                list[left] = list[j];
                list[j] = temp;
                break;
            }
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
        
 
    quicksort(list, left, j-1);
    quicksort(list, j+1, right);

}

int main()
{
    int n = 0;
    int list[8] = {21, 10, 12, 20, 25, 13, 15, 22};

    quicksort(list, 0, 7);

    printf("정렬전 배열 : 21, 10, 12, 20, 25, 13, 15, 22\n");
    printf("정렬된 배열 : ");
    for(int i = 0; i<8; i++)
    {
        printf("%d, ",list[i]);
    }
    printf("\n");
    return 0;

}