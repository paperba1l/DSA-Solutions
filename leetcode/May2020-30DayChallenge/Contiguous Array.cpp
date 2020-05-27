class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int len = nums.size();

        unordered_map<int, int> mpp;
        mpp[0] = -1;

        int mx_len = 0, sm = 0;
        for (int i = 0; i < len; i++)
        {
            int a = nums[i] == 1 ? 1 : -1;

            sm += a;

            if (mpp.find(sm) != mpp.end())
            {
                mx_len = max(mx_len, i - mpp[sm]);
            }
            else
            {
                mpp[sm] = i;
            }
        }

        return mx_len;
    }
};