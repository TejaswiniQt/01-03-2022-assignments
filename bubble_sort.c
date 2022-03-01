/*****Bubble sort*******/

#include<stdio.h>
#define N 5

void bubble(int *arr);

int main()
{
    int i;
    int arr[N];
    printf("Enter the elements of the array:\n");
    for(i=0;i<N;i++)
    {
        scanf("%d",arr+i);
    }
    
    bubble(arr);
    
    printf("Array after sorting:\n");
    for(i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

void bubble(int *arr)
{
    int i,j,temp;
    
    for(i=1;i<N;i++)
    {
        for(j=0;j<N-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
        
