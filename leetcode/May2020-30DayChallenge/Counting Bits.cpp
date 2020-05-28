class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1, 0);

        for (int i = 0; i <= num; i++)
        {
            if (i % 2 == 0)
            {
                ans[i] = ans[i >> 1];
            }
            else
            {
                ans[i] = ans[i >> 1] + 1;
            }
        }
        return ans;
    }
};