class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int ans = 0, sm = 0;
        unordered_map<int, int> mpp;

        mpp[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                nums[i] = -1;

            sm += nums[i];
            if (mpp.find(sm) != mpp.end())
            {
                ans = max(ans, i - mpp[sm]);
            }
            else
            {
                mpp[sm] = i;
            }
        }

        return ans;
    }
};