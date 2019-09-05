/**
 *  @author:      skyhavoc
 *  created:      2019
**/
int Solution::solve(vector<string> &a)
{
    sort(a.begin(), a.end());

    int i = 0, j = a.size() - 1;
    double sum;
    while (i < j - 1)
    {
        sum = stod(a[i]) + stod(a[j]) + stod(a[i + 1]);
        if (sum > 2)
            j--;
        else if (sum < 1)
            i++;
        else
            return 1;
    }
    return 0;
}
