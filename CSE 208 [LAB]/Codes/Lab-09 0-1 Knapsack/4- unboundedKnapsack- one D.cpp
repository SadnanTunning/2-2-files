#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int cpt, int n,int val[], int wt[])
{

    int dp[cpt+1];
    memset(dp, 0, sizeof dp);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=cpt; j++)
        {
            if (wt[i] <= j)
                dp[j] = max(dp[j], dp[j-wt[i]] + val[i]);
            printf("%d    ",dp[j]);
        }
        printf("\n");
    }


    return dp[cpt];
}

// Driver program
int main()
{
    int cpt = 10;
    int val[] = {2, 1, 7, 6, 12};
    int  wt[] = {1, 2, 3, 4, 6};
    int n = sizeof(val)/sizeof(val[0]);

    printf("\nmax value: %d", unboundedKnapsack(cpt, n, val, wt));

    return 0;
}
