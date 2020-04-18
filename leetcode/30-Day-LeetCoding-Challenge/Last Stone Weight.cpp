class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (auto e : stones)
        {
            pq.push(e);
        }

        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            if (a != b)
            {
                pq.push(a - b);
            }
        }
        if (pq.empty())
            return 0;
        else
        {
            return pq.top();
        }
    }
};