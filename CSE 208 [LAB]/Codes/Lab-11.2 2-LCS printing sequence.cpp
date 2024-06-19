//Tabulation bottom-up way
#include<bits/stdc++.h>
using namespace std;

void lcs(char *S1, char *S2, int m, int n)
{
    int LCS_table[m + 1][n + 1];

    // Building the mtrix in bottom-up way
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCS_table[i][j] = 0;

            else if (S1[i] == S2[j])
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            else
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
        }
    }

    int index = LCS_table[m][n];
    char lcs_sqns[index + 1];
    lcs_sqns[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            lcs_sqns[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }

        else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }

    // Printing the sub sequences
    cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcs_sqns << "\n";
    cout << "\nLength of longest common subsequence " <<LCS_table[m][n]<<endl;
}

int main()
{
    char S1[] = "BD";
    char S2[] = "ACBD";
    int M = strlen(S1);
    int N = strlen(S2);

    lcs(S1, S2, M, N);
}
