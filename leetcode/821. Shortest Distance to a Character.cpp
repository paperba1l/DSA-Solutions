class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {

        stack<int> stk;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
            {
                stk.push(i);
            }
        }

        vector<int> vec(s.length());
        int r = stk.top(), l = stk.top();
        stk.pop();
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (!stk.empty() and i <= l)
            {
                r = l;
                l = stk.top();
                stk.pop();
            }
            vec[i] = min(abs(i - r), abs(i - l));
        }

        return vec;
    }
};