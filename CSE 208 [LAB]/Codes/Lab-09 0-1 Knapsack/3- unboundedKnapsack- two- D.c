#include<stdio.h>
int max(int a, int b)
{
    return (a > b)? a : b;
}

int knapSack(int wt[], int val[], int cpt, int n)
{
    int dp[n + 1][cpt + 1];

    for (int i=0; i<=n; i++)
        for (int j=0; j<=cpt; j++)
            dp[i][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= cpt; j++)
        {
            if(wt[i-1]<=j)
                dp[i][j]=max((val[i-1]+dp[i][j - wt[i - 1]]),dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];

            printf("%d    ",dp[i][j]);
        }
        printf("\n");
    }

    printf("\nMax Value:\t%d",dp[n][cpt]);

    printf("\nSelected Packs: \n");

    while (cpt != 0)
    {
        if (dp[n][cpt] != dp[n - 1][cpt])
        {
            printf("\tPackage %d with Wt = %d and Val = %d\n",n,  wt[n-1], val[n-1] );
            cpt = cpt - wt[n-1];
            n++;
        }
        n--;
    }

}

int main()
{
    int cpt = 10;
    int val[] = {2, 1, 7, 6, 12};
    int  wt[] = {1, 2, 3, 4, 6};
    int n = sizeof(val)/sizeof(val[0]);
    knapSack(wt, val, cpt, n);
    return 0;
}
