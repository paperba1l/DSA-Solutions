class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &a)
    {

        sort(a.begin(), a.end());

        int len = a.size();
        vector<vector<int>> ans;
        for (int i = 0; i < len - 2; i++)
        {
            // remove ai duplicate
            if (i > 0 and a[i] == a[i - 1])
                continue;

            long long int l = i + 1, r = len - 1, sm = 0;

            while (l < r)
            {
                sm = (long long int)(a[i] + 0LL + a[l] + a[r]);

                if (sm == 0)
                {
                    ans.push_back({a[i], a[l], a[r]});
                    l++;
                    while (l < r and a[l] == a[l - 1])
                        l++;
                }
                else if (sm < 0)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};