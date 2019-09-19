int Solution::diffPossible(vector<int> &A, int B)
{
    int n = A.size();

    int j = 0, i = 1;
    while (i < n and j < n)
    {
        if (i != j && (A[i] - A[j]) == B)
        {
            return true;
        }
        else if ((A[i] - A[j]) < B)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return false;
}
