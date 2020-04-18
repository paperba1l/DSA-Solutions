class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int prod = 1, prod_ex_0 = 1, cnt0 = 0, n = nums.size();
        for (auto e : nums)
        {
            prod *= e;
            if (e == 0)
            {
                cnt0++;
            }
            else
            {
                prod_ex_0 *= e;
            }
        }

        vector<int> ans(n);

        if (cnt0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                ans[i] = (prod / nums[i]);
            }
        }
        else
        {
            if (cnt0 == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (nums[i] != 0)
                    {
                        ans[i] = 0;
                    }
                    else
                    {
                        ans[i] = prod_ex_0;
                    }
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    ans[i] = 0;
                }
            }
        }

        return ans;
    }
};