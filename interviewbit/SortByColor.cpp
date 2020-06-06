/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      Sort by Color
**/
void Solution::sortColors(vector<int> &a)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int len = a.size();
    int l = 0, curr = 0, r = len - 1;
    if (len <= 1)
        return;

    while (curr <= r)
    {
        if (a[curr] == 1)
        {
            curr++;
        }
        else if (a[curr] == 0)
        {
            swap(a[curr], a[l]);
            l++;
            curr++;
        }
        else
        {
            swap(a[curr], a[r]);
            r--;
        }
    }
}
