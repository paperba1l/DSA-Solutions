class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int l = -1, curr = 0, r = nums.size() - 1;

        while (curr <= r)
        {
            if (nums[curr] == 1)
            {
                curr++;
            }
            else if (nums[curr] == 0)
            {
                l++;
                swap(nums[l], nums[curr]);
                curr++;
            }
            else
            {
                swap(nums[curr], nums[r]);
                r--;
            }
        }
    }
};