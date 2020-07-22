class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &nums)
    {

        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]].push_back(i);

            if (mpp[nums[i]].size() == nums[i])
            {
                ans.push_back(mpp[nums[i]]);
                mpp[nums[i]].resize(0);
            }
        }
        return ans;
    }
};