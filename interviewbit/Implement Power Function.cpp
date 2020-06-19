int Solution::pow(int x, int n, int d)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if (n == 0)
        return 1 % d;

    long long int ans = 1, t = x % d;
    x = x % d;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = (ans * t) % d;
        }
        t = (t * t) % d;
        n >>= 1;
    }

    ans = (ans + d) % d;

    return ans;
}
