/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      Sliding Window Maximum
 * Given an array of integers A. There is a sliding window of size B which
is moving from the very left of the array to the very right.
You can only see the w numbers in the window. Each time the sliding window moves
rightwards by one position. You have to find the maximum for each window.
The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.
**/
vector<int> Solution::slidingMaximum(const vector<int> &A, int B)
{
    int n = A.size();
    multiset<int> sett;

    for (int i = 0; i < n; i++)
    {
        if (sett.size() < B)
        {
            sett.insert(A[i]);
        }
    }
    vector<int> ans;
    ans.push_back(*sett.rbegin());

    for (int i = B; i < n; i++)
    {
        sett.insert(A[i]);
        multiset<int>::iterator it = sett.find(A[i - B]);
        sett.erase(it);

        ans.push_back(*sett.rbegin());
    }
    return ans;
}
