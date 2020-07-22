class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[n - 1] = 1;
        int prev_good = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if ((i + nums[i]) >= prev_good)
            {
                dp[i] = 1;
                prev_good = i;
            }
        }

        return dp[0] == 1;
    }
};