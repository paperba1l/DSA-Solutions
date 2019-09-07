/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      Max Non Negative SubArray
**/
/*
Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.
*/
vector<int> Solution::maxset(vector<int> &a)
{
    int start = -1, end = -1;
    int l = 0, r = 0;
    long long int sum = 0, maxsum = 0;

    int n = a.size(), i = 0;
    while (i < n)
    {
        if (a[i] >= 0)
        {
            sum += (long long int)a[i];
            r++;
        }
        if (a[i] < 0)
        {
            l = i + 1;
            r = i + 1;
            sum = 0LL;
        }

        if (sum > maxsum)
        {
            maxsum = sum;
            start = l;
            end = r;
        }
        if (sum == maxsum)
        {
            maxsum = sum;
            if ((r - l) > (end - start))
            {
                start = l;
                end = r;
            }
        }
        i++;
    }
    vector<int> vec;
    for (int i = start; i < end; i++)
    {
        vec.push_back(a[i]);
    }
    return vec;
}
