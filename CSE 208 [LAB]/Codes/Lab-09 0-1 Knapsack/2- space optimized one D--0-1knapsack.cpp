#include <bits/stdc++.h>
using namespace std;
int knapSack(int cpt, int wt[], int val[], int n)
{
    int dp[cpt + 1];
    memset(dp, 0, sizeof(dp));

   for (int i=0; i<n; i++)
    {
        printf("i=%d\n", i);
        for (int j=0; j<=cpt; j++)
        {
            printf("wt[i-1]=%d, j=%d\t", wt[i-1],j);
            if (wt[i - 1] <= j)
                dp[j] = max(dp[j],dp[j - wt[i - 1]] + val[i - 1]);
            printf("dp[%d]= %d\n",j,dp[j]);
        }
        printf("\n\n");
    }
    return dp[cpt];
}
int main()
{
    int wt[] = {2, 3, 4, 5};
    int val[] = {3, 4, 5, 6};
    int cpt = 5;
    int n = sizeof(val) / sizeof(val[0]);
    printf("max value gain: %d", knapSack(cpt, wt, val, n));
    return 0;
}
