int Solution::isInterleave(string A, string B, string C)
{

    int len1 = A.length(), len2 = B.length(), len3 = C.length();
    if (len1 + len2 != len3)
        return false;

    vector<vector<bool>> dp(len2 + 10, vector<bool>(len1 + 10, false));

    dp[0][0] = true;
    for (int i = 1; i <= len1; i++)
    {
        if (A[i - 1] == C[i - 1])
        {
            dp[0][i] = dp[0][i - 1];
        }
    }
    for (int i = 1; i <= len2; i++)
    {
        if (B[i - 1] == C[i - 1])
        {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int i = 1; i <= len2; i++)
    {
        for (int j = 1; j <= len1; j++)
        {
            if (C[i + j - 1] == A[j - 1] and C[i + j - 1] == B[i - 1])
            {
                dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
            }
            else if (C[i + j - 1] == A[j - 1])
            {
                dp[i][j] = dp[i][j - 1];
            }
            else if (C[i + j - 1] == B[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[len2][len1];
}