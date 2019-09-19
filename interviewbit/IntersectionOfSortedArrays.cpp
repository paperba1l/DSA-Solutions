vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B)
{
    int n1 = A.size(), n2 = B.size(), i = 0, j = 0;

    vector<int> vec;
    while (i < n1 and j < n2)
    {
        if (A[i] == B[j])
        {
            vec.push_back(A[i]);
            i++;
            j++;
        }
        else if (A[i] > B[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return vec;
}
