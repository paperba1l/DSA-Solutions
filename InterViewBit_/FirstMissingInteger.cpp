/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      First Missing Integer interviewbit
**/

int Solution::firstMissingPositive(vector<int> &A)
{
    int n = A.size();

    // i will increment when Ai is negetive or greater than n
    // or a[i] points to a dubplicate number
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0 && A[i] <= n)
        {
            int pos = A[i] - 1;
            if (A[pos] != A[i])
            {
                swap(A[pos], A[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] != i + 1)
            return (i + 1);
    }
    return n + 1;
}
// { 6,5,1,3,7,8,4,2} first get 1 is correct place (0th index) then progress
