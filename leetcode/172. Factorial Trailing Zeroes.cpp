typedef long long int ll;
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int x = 0;
        if (n <= 4)
        {
            return 0;
        }
        else
        {
            /*
                    we need to count total power of 5 in the factorial
                    count multiple of 5 - 
                    count multiple of 25 - if there are numbers with 25 as factor, then increment the power of 5 found so far by the number of multiples of 25 in the range [1...N]
                    count multiple of 125 - same
                */
            ll m = 5;
            while (n / m != 0)
            {
                x += (int)n / m;
                m = m * 5;
            }
        }
        return x;
    }
};