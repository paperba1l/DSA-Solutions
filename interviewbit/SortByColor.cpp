/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      Sort by Color
**/
void Solution::sortColors(vector<int> &a)
{
    int n = a.size();

    int idx_0 = 0, idx_2 = n - 1, i = 0;
    while (i <= idx_2)
    {
        if (a[i] == 0)
        {
            swap(a[i], a[idx_0]);
            idx_0++;
            i++;
        }
        else if (a[i] == 1)
        {
            i++;
        }
        else
        {
            swap(a[i], a[idx_2]);
            idx_2--;
        }
    }
}
// 0 1 2 0 1 2]