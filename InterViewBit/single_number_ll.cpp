
int Solution::singleNumber(const vector<int> &a)
{
    int ones = 0, twos = 0;
    for (int i = 0; i < a.size(); i++)
    {
        // add bits to twos which occour 2 times in ones
        twos |= a[i] & ones;

        // just plain cummulative xor
        ones ^= a[i];

        // the bits which are common occour thrice, because in twos the bit is set and
        // in ones the same bit just turned set in the previous xor opperation. So, remove
        // set bits from ones as ones store the answer.
        int common_bit = ones & twos;
        ones -= common_bit;
        twos -= common_bit;
    }
    return ones;
}
