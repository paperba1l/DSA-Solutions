class Solution
{
public:
    string frequencySort(string s)
    {

        sort(s.begin(), s.end());

        int len = 1, prev_char = s[0];
        priority_queue<pair<int, char>> pq;
        for (int i = 1; i <= s.length(); i++)
        {
            if (i == s.length())
            {
                pq.push({len, prev_char});
            }
            else if (prev_char != s[i])
            {
                pq.push({len, prev_char});
                len = 1;
                prev_char = s[i];
            }
            else
            {
                len++;
            }
        }

        string ans = "";
        while (!pq.empty())
        {
            auto e = pq.top();
            cout << e.first << " " << e.second << endl;
            for (int i = 0; i < e.first; i++)
            {
                ans += e.second;
            }
            pq.pop();
        }

        return ans;
    }
};