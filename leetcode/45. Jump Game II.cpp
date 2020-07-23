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

        int maxReach = nums[0], // max index you can reach so far
            steps = nums[0],    // from an index i how many steps(i unit) you can take
            jump = 1;           // answer variable

        for (int i = 1; i < n; i++)
        {
            if (i == (n - 1))
                return jump;

            maxReach = max(maxReach, i + nums[i]); // just track max index reachable
            steps--;                               // if you have reached index i then you have jumped, decrement steps

            // if you have reached the max reachable point from point i,
            // then its time to take a new jump
            if (steps == 0)
            {
                jump++; // increase jump

                // if we are at index i and max-reachable is lesser or equal to it self, then
                //  cannot reach the end
                if (maxReach <= i)
                {
                    return -1;
                }

                // from index i count how many more (1 unit) steps are needed
                steps = maxReach - i;
            }
        }
        return -1;
    }
};