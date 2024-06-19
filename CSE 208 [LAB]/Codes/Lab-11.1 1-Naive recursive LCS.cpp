#include <bits/stdc++.h>
using namespace std;

int M,N;

// For calculating the length of the longest common subsequence

int lcs(string S1, string S2, int i, int j)
{
    if (i == M || j == N)
        return 0;

    if (S1[i] == S2[j])
        return (lcs(S1, S2, i+1, j+1) + 1);
    else
        return max(lcs(S1, S2, i+1, j), lcs(S1, S2, i, j+1));
}



int main()
{

    string S1 = "bd";
    string S2 = "acbd";
    M = S1.length();
    N = S2.length();
    cout << "Length of longest common subsequence " << lcs(S1, S2, 0, 0);

    return 0;
}
