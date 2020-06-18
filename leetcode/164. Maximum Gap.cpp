class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int len = nums.size(), mx = INT_MIN, mn = INT_MAX;

        if (len < 2)
            return 0;

        mx = *max_element(nums.begin(), nums.end());
        mn = *min_element(nums.begin(), nums.end());

        int gap = ceil((double)(mx - mn) / (double)(len - 1));
        if (gap == 0)
        { // if mx == mn
            return 0;
        }

        vector<int> bucket_min(len, INT_MAX), bucket_max(len, INT_MIN);

        for (int i = 0; i < len; i++)
        {
            int idx = (nums[i] - mn) / gap;

            if (bucket_min[idx] == INT_MAX)
            {
                bucket_min[idx] = nums[i];
            }
            else
            {
                bucket_min[idx] = min(bucket_min[idx], nums[i]);
            }

            if (bucket_max[idx] == INT_MIN)
            {
                bucket_max[idx] = nums[i];
            }
            else
            {
                bucket_max[idx] = max(bucket_max[idx], nums[i]);
            }
        }

        int prev_idx = 0, max_diff = gap - 1;
        for (int i = 0; i < len; i++)
        {
            if (bucket_min[i] == INT_MAX and bucket_max[i] == INT_MIN)
            {
                continue;
            }
            else
            {
                max_diff = max(max_diff, bucket_min[i] - bucket_max[prev_idx]);
                prev_idx = i;
            }
        }
        return max_diff;
    }
};