int Solution::minDistance(string A, string B)
{
    int len1 = A.length(), len2 = B.length();
    vector<vector<int>> dp(len2 + 10, vector<int>(len1 + 10, 0));

    for (int i = 0; i <= len1; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 0; i <= len2; i++)
    {
        dp[i][0] = i;
    }

    for (int r = 1; r <= len2; r++)
    {
        for (int c = 1; c <= len1; c++)
        {
            if (A[c - 1] == B[r - 1])
            {
                dp[r][c] = dp[r - 1][c - 1];
            }
            else
            {
                dp[r][c] = 1 + min({dp[r - 1][c - 1], dp[r - 1][c], dp[r][c - 1]});
            }
        }
    }

    return dp[len2][len1];
}
