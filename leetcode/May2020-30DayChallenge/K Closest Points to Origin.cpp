class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {

        vector<pair<int, vector<int>>> lis;

        for (auto e : points)
        {
            int dis = e[0] * e[0] + e[1] * e[1];
            lis.push_back({dis, e});
        }

        sort(lis.begin(), lis.end());

        vector<vector<int>> vec;
        for (int i = 0; i < K; i++)
        {
            vec.push_back(pq[i].second);
        }
        return vec;
    }
};