vector<int> Solution::prevSmaller(vector<int> &A)
{
    int n = A.size();

    vector<int> res(n, -1);
    stack<int> stk;
    stk.push(n - 1);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!stk.empty() and A[i] < A[stk.top()])
        {
            res[stk.top()] = A[i];
            stk.pop();
        }
        stk.push(i);
    }
    return res;
}
