class Solution
{
public:
    string proc(string s)
    {
        int l = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#')
            {
                if (l > 0)
                    l--;
            }
            else
            {

                s[l] = s[i];
                l++;
            }
        }
        while (l < s.length())
        {
            s[l] = '#';
            l++;
        }
        return s;
    }
    bool backspaceCompare(string S, string T)
    {

        string _s1 = proc(S), _s2 = proc(T);

        for (int i = 0; i < min(_s1.length(), _s2.length()); i++)
        {
            if (_s1[i] != _s2[i])
            {
                return false;
            }
        }

        return true;
    }
};