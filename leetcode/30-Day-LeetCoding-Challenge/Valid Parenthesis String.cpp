class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> stk1, stk2;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                stk1.push(i);
            }
            else if (s[i] == '*')
            {
                stk2.push(i);
            }
            else
            {
                if (!stk1.empty())
                {
                    stk1.pop();
                }
                else if (!stk2.empty())
                {
                    stk2.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        if (stk1.size() > stk2.size())
        {
            return false;
        }

        while (!stk1.empty() and !stk2.empty())
        {
            if (stk1.top() < stk2.top())
            {
                stk1.pop();
                stk2.pop();
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};