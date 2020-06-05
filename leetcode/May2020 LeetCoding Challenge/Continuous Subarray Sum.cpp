class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int len = nums.size();

        if (len <= 1)
            return false;
        unordered_map<int, int> mpp;

        int sm = 0;
        mpp[0] = -1;
        for (int i = 0; i < len; i++)
        {
            int e = nums[i];
            sm = (e + sm);
            if (k != 0)
                sm = sm % k;

            if (mpp.find(sm) != mpp.end() and (i - mpp[sm]) > 1)
            {
                return 1;
            }

            if (mpp.find(sm) == mpp.end())
            {
                mpp[sm] = i;
            }
        }
        return 0;
    }
};