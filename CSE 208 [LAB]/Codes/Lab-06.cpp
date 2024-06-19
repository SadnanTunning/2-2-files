#include<bits/stdc++.h>
using namespace std;

struct activity
{
    int st, fi;
};
bool sort_way(activity s1, activity s2)
{
    return(s1.fi<s2.fi);
}

void maxacivity( activity arr[], int n)
{
    sort(arr,arr+n,sort_way);
    printf ("Following activities are selected n \n");
    int i=0;
    cout<<"["<<arr[i].st<<" "<<arr[i].fi<<"]"<<endl;
    for(int j=1;j<n;j++)
    {\
        if (arr[j].st>=arr[i].fi)
        {
            cout<<"["<<arr[j].st<<" "<<arr[j].fi<<"]"<<endl;
            i=j;
        }
    }
}

int main()
{
     activity arr[100];
     int n;
     cout<<"Enter n:";
     cin>>n;
     for(int i=0; i<n;i++)
     {
         cout<<"Enter sart time and finish time of "<<i+1<<"th activity\n";
         cin>>arr[i].st>>arr[i].fi;
     }
     maxacivity(arr,n);

}
