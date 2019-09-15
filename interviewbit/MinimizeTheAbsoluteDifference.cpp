int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{

    int n1 = A.size() - 1, n2 = B.size() - 1, n3 = C.size() - 1;

    int min_diff = max(A[n1], max(B[n2], C[n3])) - min(A[n1], min(B[n2], C[n3]));

    while (n1 != -1 and n2 != -1 and n3 != -1)
    {
        int tmp = max(A[n1], max(B[n2], C[n3])) - min(A[n1], min(B[n2], C[n3]));
        if (tmp < min_diff)
        {
            min_diff = tmp;
        }

        int max_term = max(A[n1], max(B[n2], C[n3]));
        if (A[n1] == max_term)
        {
            n1--;
        }
        else if (B[n2] == max_term)
        {
            n2--;
        }
        else
        {
            n3--;
        }
    }
    return min_diff;
}
