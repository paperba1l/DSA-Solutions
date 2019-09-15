/**
 * @author:     skyhavoc
 * created:     2019
 * problem:     Remove Element from Array
 * Given an array and a value, remove all the instances of that value in the array.
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.
**/
int Solution::removeElement(vector<int> &A, int B)
{

    int j = 0, n = A.size();
    for (int i = 0; i < n; i++)
    {
        if (A[i] != B)
        {
            A[j] = A[i];
            j++;
        }
    }
    return j;
}

// 4, 1, 1, 2, 1, 3