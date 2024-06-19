#include<bits/stdc++.h>
using namespace std;

knapsack(int n,float w[],float v[],float c)
{
    float tp, frac;
    int i;
    for(i=0; i< n; i++)
    {
        if (w[i]>c)
            break;
        else
        {
            tp=tp+v[i];
            c=c-w[i];
            printf(" Taken completely %.0f kg, TP:%.2f  cpt left%.2f\n",w[i],tp,c);
        }
    }

    frac=c/w[i];
    tp=tp+frac*v[i];
    printf(" Fractionally taken completely %.2f TP:%.2f \n",frac,tp);
}
int main()
{
    float w[100], v[100], r[100], c;
    int n,i,j;
    cout<< "enter n: ";
    cin>>n;

    for(i=0; i<n; i++)
    {
        cin>>w[i]>>v[i];
        r[i]=v[i]/w[i];
    }
    cin>>c;
    float temp;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(r[i]<r[j])
            {
                temp=r[j];
                r[j]=r[i];
                r[i]=temp;

                temp=v[j];
                v[j]=v[i];
                v[i]=temp;

                temp=w[j];
                w[j]=w[i];
                w[i]=temp;
            }
        }
    }
    cout<<endl;
    for(i=0; i<n; i++)
        printf("%.0f \t%.0f\t%.2f\n",w[i],v[i],r[i]);

    knapsack(n, w,v,c);

}
