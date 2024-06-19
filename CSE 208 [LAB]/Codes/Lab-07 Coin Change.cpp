#include<bits/stdc++.h>
using namespace std;
int t[100];

int coinchange(int c[],int sz,int val)
{
    int cnt=0, i;
    for(i=0;i<sz;i++)
    {
        while(val>=c[i])
        {
            val-=c[i];
            t[cnt]=c[i];
            cnt++;
        }
        if(val==0)
            break;
    }
    return cnt;
}

int main()
{

    int c[]={1,5,6,9};
    int val=11,i;
    int sz=sizeof(c)/ sizeof(c[0]);

    sort(c,c+sz,greater<int>());

    int coin=coinchange(c,sz,val);

    cout<<"no. of coins: "<<coin<<endl;

    for(i=0; i<coin;i++)
        cout<<t[i]<<" ";

}
