
/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      Merge Overlapping Intervals
 * Given a collection of intervals, merge all overlapping intervals. 
 * Done using stack and without it
**/
int cmp(Interval a, Interval b)
{
    return a.start < b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A)
{
    sort(A.begin(), A.end(), cmp);

    vector<Interval> res;
    res.push_back(A[0]);
    for (int i = 1; i < n; i++)
    {
        if (A[i].start > res[res.size() - 1].end)
        {
            res.push_back(A[i]);
        }
        else
        {
            res[res.size() - 1].start =
        }
    }
}

/* using stack
bool cmp(Interval a, Interval b)
{
    return a.start < b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A)
{
    sort(A.begin(), A.end(), cmp);

    stack<Interval> stk;
    stk.push(A[0]);
    for (int i = 1; i < A.size(); i++)
    {
        if (!stk.empty() and A[i].start > stk.top().end)
        {
            stk.push(A[i]);
        }
        else
        {
            Interval cur_interval = A[i];
            while (!stk.empty() and cur_interval.start <= stk.top().end)
            {
                cur_interval.end = max(cur_interval.end, stk.top().end);
                cur_interval.start = min(cur_interval.start, stk.top().start);
                stk.pop();
            }
            stk.push(cur_interval);
        }
    }
    vector<Interval> vec;
    while (!stk.empty())
    {
        vec.insert(vec.begin(), stk.top());
        stk.pop();
    }
    return vec;
}
*/