class Solution
{
public:
    int mpp[26], mps[26];

    bool compare()
    {
        int flag = true;

        for (int i = 0; i < 26; i++)
        {
            if (mpp[i] == 0)
                continue;

            if (mpp[i] != mps[i])
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
    vector<int> findAnagrams(string s, string p)
    {
        int len1 = s.length(), len2 = p.length();
        vector<int> ans;

        if (len2 > len1)
            return ans;

        for (int i = 0; i < len2; i++)
        {
            mpp[(int)(p[i] - 'a')]++;
            mps[(int)(s[i] - 'a')]++;
        }

        if (compare())
            ans.push_back(0);

        for (int i = len2; i < len1; i++)
        {
            mps[(int)(s[i - len2] - 'a')]--;
            mps[(int)(s[i] - 'a')]++;

            if (compare())
            {
                ans.push_back(i - len2 + 1);
            }
        }

        return ans;
    }
};