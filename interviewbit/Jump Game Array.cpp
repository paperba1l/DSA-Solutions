int Solution::canJump(vector<int> &a)
{

    int len = a.size();
    if (len == 0)
        return 0;
    if (len == 1)
        return 1;

    vector<int> dp(2 * len, 0);
    dp[0] = 1;
    for (int i = 0; i < len; i++)
    {
        if (dp[i] == 1)
        {
            for (int j = 1; j <= a[i]; j++)
            {
                dp[i + j] = 1;
            }
        }
    }

    return dp[len - 1];
}