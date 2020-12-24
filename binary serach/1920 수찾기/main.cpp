#include<iostream>
#include<algorithm>
using namespace std;

int list[100001];

// void swap(int *list, int a, int b)
// {
//     int tmp = list[a];
//     list[a] = list[b];
//     list[b] = tmp; 
// }

// void quicksort(int *list, int start, int end)
// {
//     int pivot = list[start];
//     int left = start + 1;
//     int right = end;

//     while(left <= right)
//     {
//         while(list[left] < pivot){left++;}
//         while(list[right] > pivot){right--;}
        
//         if(left<= right)swap(list,left,right);
//     }

//     if(start < end)
//     {
//         swap(list,start, right);

//         quicksort(list,start,right-1);
//         quicksort(list,right+1,end);
//     }

//     return;
// }

int binarysearch( int low, int high, int key)
{
    high -= 1;
    int mid;

    while(low <= high)
    {
        mid = (low+high)/2;
        if(list[mid] == key)
        {
            return 1;
        }   
        else if(list[mid] > key)
            high = mid-1;
        else
            low = mid+1;
    }
    
    return 0;

}

int main()
{
    
    int search;
    int num;
    int num_key;

    cin >> num;

    for(int i = 0; i<num; i++)
    {
        scanf("%d",&list[i]);
    }
    
    // quicksort(list,0,num-1);
    sort(list, list+num);
    scanf("%d",&num_key);

    // for(int i=0; i < num_key; i++)
    // {
    //     scanf("%d",&search[i]);
    // } 
    
    for(int i = 0; i < num_key; i++)
    {
        scanf("%d",&search);
       
       printf("%d\n",binarysearch( 0, num, search));
        
    }

    return 0;
}