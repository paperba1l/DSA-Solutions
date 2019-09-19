void Solution::nextPermutation(vector<int> &a)
{
    int n = a.size(), idx, idx2;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            idx = i;
            break;
        }
    }
    if (idx == 0 and (a[0] > a[1]))
        return;

    for (int i = n - 1; i > idx; i--)
    {
        if (a[i] > a[idx])
        {
            idx2 = i;
            break;
        }
    }

    swap(a[idx], a[idx2]);
    sort(a.begin() + idx + 1, a.end());
}
