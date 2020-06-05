class Solution
{
public:
    string removeKdigits(string nums, int k)
    {
        if (k == 0)
            return nums;
        if (k == nums.length())
            return "0";

        stack<char> stk;
        stk.push(nums[0]);

        for (int i = 1; i < nums.length(); i++)
        {
            while (k > 0 and !stk.empty() and stk.top() > nums[i])
            {
                stk.pop();
                k--;
            }

            if (nums[i] != '0' or (nums[i] == '0' and !stk.empty()))
            {
                stk.push(nums[i]);
            }
        }

        while (k > 0 and !stk.empty())
        {
            stk.pop();
            k--;
        }
        if (stk.size() == 0)
            return "0";

        nums = "";
        while (!stk.empty())
        {
            nums.push_back(stk.top());
            stk.pop();
        }

        reverse(nums.begin(), nums.end());

        return nums;
    }
};