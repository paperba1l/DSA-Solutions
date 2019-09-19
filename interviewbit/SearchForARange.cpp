vector<int> Solution::searchRange(const vector<int> &A, int B)
{
    int n = A.size();
    int l_idx = -1, r_idx = -1;

    vector<int> res{-1, -1};
    if ((n >= 1 and B > A[n - 1]) or B < A[0])
    {
        return res;
    }
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + (r - l) / 2);
        if (A[m] == B)
        {
            res[0] = m;
            r = m - 1;
        }
        if (A[m] < B)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    l = res[0], r = n - 1, r_idx = res[0];
    while (l <= r)
    {
        int m = (l + (r - l) / 2);
        if (A[m] == B)
        {
            res[1] = m;
            l = m + 1;
        }
        if (A[m] <= B)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return res;
}