class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int l = 1, r = num;

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (num % m == 0 and m == (num) / m)
                return true;

            if (m < (int)((num) / m))
                l = m + 1;
            else
                r = m - 1;
        }

        return false;
    }
};