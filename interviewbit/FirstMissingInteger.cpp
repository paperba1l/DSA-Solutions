/**
 *  @author:      skyhavoc / Aman Nidhi
 *  created:      2019
 *  problem:      First Missing Integer interviewbit
**/
int Solution::firstMissingPositive(vector<int> &a)
{

    int idx = 0, n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
        {
            swap(a[i], a[idx]);
            idx++;
        }
    }
    if (idx == n)
        return 1;
    a.erase(a.begin(), a.begin() + idx);

    n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) - 1 < n and a[abs(a[i]) - 1] > 0)
        {
            a[abs(a[i]) - 1] *= -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            return i + 1;
    }
    return n + 1;
}
