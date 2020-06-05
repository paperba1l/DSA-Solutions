class Solution
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        sort(A.begin(), A.end(), compare);
        sort(B.begin(), B.end(), compare);

        int i = 0, j = 0, len1 = A.size(), len2 = B.size();

        vector<vector<int>> vec;
        while (i < len1 and j < len2)
        {
            int l = -1, r = 2e9;

            l = max(A[i][0], B[j][0]);
            r = min(A[i][1], B[j][1]);

            if (l <= r)
            {
                vec.push_back({l, r});
            }

            if (r == A[i][1])
                i++;
            else
                j++;
        }

        return vec;
    }
};