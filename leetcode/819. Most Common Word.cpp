class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        int n = paragraph.length();
        map<string, int> mpp;
        string s = "";
        for (int i = 0; i <= n; i++)
        {
            if (i < n and isalpha(paragraph[i]))
            {
                s += tolower(paragraph[i]);
            }
            else
            {
                if (s.length() > 0)
                {
                    mpp[s]++;
                    s = "";
                }
            }
        }

        for (auto e : banned)
        {
            mpp.erase(e);
        }

        int max_count = 0;
        string ans = "";
        for (auto e : mpp)
        {
            if (e.second > max_count)
            {
                ans = e.first;
                max_count = e.second;
            }
        }
        return ans;
    }
};