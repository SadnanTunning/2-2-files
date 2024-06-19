#include<bits/stdc++.h>
using namespace std;

int max3(int a, int b, int c)
{
    return max(max(a,b),c);
}

int allsum( int arr[], int low, int mid, int high)
{
    int sum=0, i;
    int Lsum=INT_MIN; int Rsum=INT_MIN;
    for(i=mid; i>=low; i--)
    {
        sum=sum+arr[i];
        if(sum>Lsum)
            Lsum=sum;
    }
    sum=0;
    //i=0;
    for(i=mid+1; i<=high; i++)
    {
        sum=sum+arr[i];
        if(sum>Rsum)
            Rsum=sum;
    }
    return Lsum+Rsum;
}

int mss(int arr[], int low, int high)
{
    if(low==high)
        return arr[low];
    else
    {
        int mid=low+(high-low)/2;
        int lsum=mss(arr, low, mid);
        int rsum=mss(arr, mid+1, high);

        int crossum=allsum(arr,low, mid,high);

        return max3(lsum,rsum,crossum);
    }
}

int main()
{
    int arr[]= {-2, -5, 6, -2, -3, 1, 5, -6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result = mss(arr, 0,n-1);
    printf("max sub array sum=%d\n", result);

}
