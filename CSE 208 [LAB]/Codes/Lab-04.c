#include<stdio.h>
int partition(int arr[], int lo, int hi)
{
    int pivot=arr[lo];
    int i=lo;
    int j=hi+1;
    int temp;

    while(i<j)
    {
        do
        {
            i++;
        }
        while(arr[i]<pivot && lo<=hi);

        do
        {
            j--;
        }
        while(pivot<arr[j]);

        if(i<j)
        {
            temp =arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    arr[lo]=arr[j];
    arr[j]=pivot;

    return j;
}

void quick(int arr[], int lo, int hi)
{
    int j;
    if(lo<hi)
    {
        j=partition(arr, lo, hi);
        quick(arr, lo, j-1); // left
        quick(arr,j+1, hi);
    }
}

int main()
{
    int arr[]= {10,10,16,0,12,-15,6,3,9,-5};
    int n=sizeof(arr)/ sizeof(arr[0]), i;

    printf("Before sort: \n");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    quick(arr, 0, n-1);

    printf("\nAfter sort: \n");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;


}
