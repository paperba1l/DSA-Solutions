class Solution
{
public:
    int mpp1[30], mpp2[30];

    int minSteps(string s, string t)
    {
        if (s.length() != t.length())
            return 0;

        for (int i = 0; i < s.length(); i++)
        {
            mpp1[s[i] - 'a']++;
            mpp2[t[i] - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            ans += abs(mpp1[i] - mpp2[i]);
        }
        return ans / 2;
    }
};