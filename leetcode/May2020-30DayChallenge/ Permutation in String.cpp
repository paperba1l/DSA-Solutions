class Solution
{
public:
    int mp1[30], mp2[30];

    int compare()
    {
        for (int i = 0; i < 26; i++)
        {
            if (mp1[i] > mp2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        for (int i = 0; i < s1.length(); i++)
        {
            mp2[s2[i] - 'a']++;
            mp1[s1[i] - 'a']++;
        }

        if (compare())
            return true;

        for (int i = s1.length(); i < s2.length(); i++)
        {
            mp2[s2[i - s1.length()] - 'a']--;
            mp2[s2[i] - 'a']++;

            if (compare())
                return true;
        }

        return false;
    }
};