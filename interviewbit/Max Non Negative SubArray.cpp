vector<int> Solution::maxset(vector<int> &a)
{
    int len = a.size();

    long long int ans = -1, idx = -1, idx_tmp = 0, sm = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] < 0)
        {
            sm = 0;
            idx_tmp = i + 1;
        }
        else
        {
            sm += a[i] * 1LL;

            if (sm > ans)
            {
                ans = sm;
                idx = idx_tmp;
            }
        }
    }

    vector<int> vec;
    if (idx == -1)
    {
        return vec;
    }
    for (int i = idx; i < len; i++)
    {
        if (a[i] < 0)
            break;
        vec.push_back(a[i]);
    }
    return vec;
}
