class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 1)
            return 0;
        if (nums[0] == 0)
            return -1;

        int maxReach = nums[0],
            steps = nums[0],
            jump = 1;

        for (int i = 1; i < n; i++)
        {
            if (i == (n - 1))
                return jump;

            maxReach = max(maxReach, i + nums[i]);
            steps--;

            if (steps == 0)
            {
                jump++;

                if (maxReach <= i)
                {
                    return -1;
                }
                steps = maxReach - i;
            }
        }
        return -1;
    }
};