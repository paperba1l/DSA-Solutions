class Solution
{
public:
    int trust_cnt[20000], trust_given[20000];

    int findJudge(int N, vector<vector<int>> &trust)
    {
        int n = trust.size();
        if (N == 1)
            return 1;

        for (vector<int> e : trust)
        {
            trust_cnt[e[1]]++;
            trust_given[e[0]]++;
        }

        int mx = 0, idx = 0;
        for (int i = 1; i < 10001; i++)
        {
            if (trust_cnt[i] > mx)
            {
                mx = trust_cnt[i];
                idx = i;
            }
        }

        cout << idx << " " << trust_given[idx] << " " << trust_cnt[idx] << " " << N - 1 << endl;
        if (trust_cnt[idx] == (N - 1))
        {
            return idx;
        }
        return -1;
    }
};