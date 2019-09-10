/**
 *  @author:      skyhavoc
 *  created:      20xx
**/
/*
Given an array of N integers, find the pair of integers in the array which have 
minimum XOR value. Report the minimum XOR value.
*/
int Solution::findMinXor(vector<int> &A)
{
    sort(A.begin(), A.end());
    int minXor = INT_MAX;
    int val = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        val = A[i] ^ A[i + 1];
        minXor = min(minXor, val);
    }
    return minXor;
}
// can be solved using trie
// solution min/max(a^c, b^c) < a^b
// {a, c, b} c>=a and c<=b