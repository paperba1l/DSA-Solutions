class Solution
{
public:
    int mpp[3004];

    bool uniqueOccurrences(vector<int> &a)
    {
        int cnt = 0, n = a.size(), offset = 1001;
        for (int i = 0; i < n; i++)
        {
            a[i] += offset;

            if (mpp[a[i]] == 0)
            {
                cnt++;
                mpp[a[i]]++;
            }
            else
            {
                mpp[a[i]]++;
            }
        }

        unordered_set<int> stt;
        for (int i = 0; i < 1004 + offset; i++)
        {
            if (mpp[i] > 0)
            {
                stt.insert(mpp[i]);
            }
        }
        if (cnt == stt.size())
            return true;
        return false;
    }
};