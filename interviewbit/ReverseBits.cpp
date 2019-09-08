/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      Reverse bits of an 32 bit unsigned integer
**/
unsigned int Solution::reverse(unsigned int A)
{

    unsigned int n = A, res = 0, pow2 = (1 << 31);

    while (n > 0)
    {
        if (n & 1)
        {
            res += pow2;
        }
        n >>= 1;
        pow2 >>= 1;
    }
    return res;
}