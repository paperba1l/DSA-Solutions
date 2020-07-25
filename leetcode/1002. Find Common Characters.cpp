class Solution
{
public:
    void andArray(vector<int> &a, vector<int> b)
    {
        for (int i = 0; i < 26; i++)
        {
            a[i] = min(b[i], a[i]);
        }
    }

    vector<string> commonChars(vector<string> &A)
    {
        vector<int> ans(26, INT_MAX);

        for (string s : A)
        {
            vector<int> t(26, 0);

            for (char c : s)
            {
                t[c - 'a']++;
            }

            andArray(ans, t);
        }

        vector<string> lis;

        for (char i = 'a'; i <= 'z'; i++)
        {

            if (ans[i - 'a'] > 0)
            {
                string c(1, i);

                while (ans[i - 'a'] > 0)
                {
                    lis.push_back(c);
                    ans[i - 'a']--;
                }
            }
        }
        return lis;
    }
};