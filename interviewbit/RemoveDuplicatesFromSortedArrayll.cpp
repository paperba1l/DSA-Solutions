/**
 * @author:     skyhavoc
 * created:     2019
 * problem:     Remove Duplicates from Sorted Array II
 * Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.
**/
int Solution::removeDuplicates(vector<int> &A)
{
    int n = A.size();
    if (n == 0 or n == 1)
        return n;
    int cnt = 1, k = 1;
    for (int i = 1; i < n; i++)
    {
        if (A[i] == A[i - 1])
        {
            if (cnt < 2)
            {
                A[k] = A[i];
                cnt++;
                k++;
            }
        }
        else
        {
            A[k] = A[i];
            cnt = 1;
            k++;
        }
    }
    return k;
}

// 1,1,1,1,1,1,1,2