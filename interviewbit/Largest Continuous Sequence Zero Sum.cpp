vector<int> Solution::lszero(vector<int> &a)
{

    unordered_map<int, int> mpp;
    int len = -1, l = -1, r = -1, sm = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sm += a[i];
        if (sm == 0)
        {
            if ((i + 1) > len)
            {
                l = 0;
                r = i;
                len = r - l + 1;
            }
        }

        if (mpp.find(sm) != mpp.end())
        {
            if ((i - mpp[sm]) > len)
            {
                l = mpp[sm] + 1;
                r = i;
                len = r - l + 1;
            }
        }
        else
        {
            mpp[sm] = i;
        }
    }

    vector<int> ans;
    if (len == -1)
        return ans;

    for (int i = l; i <= r; i++)
    {
        ans.push_back(a[i]);
    }
    return ans;
}
