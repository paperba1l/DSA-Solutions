
/*
A bit more info is given other than that given by the solution to help visualize the question.
Here, one wants to find the smallest k up to which the sum is greater than or equal to the target, i.e.
1 + 2 + ... + k-1 < target, and 1 + 2 + ... + k >= target
(by solving quadratic equation k*(k+1)/2 = target).

In addition, the difference betweent the sum (i.e. 1+2+...+k) and target ought to be an even number such that by reversing the sign of a number in the series (value is (sum - target)/2) the target is hit. Note that reversing a sign is equivalent to taking the number away from the series and add a negative copy.

The algo is summarized below

find k up to which the sum is greater than or equal to target;
verify 1+2+...+k - target is even; if not, increase k by 1 until the difference is even;
return k.
*/
class Solution
{
public:
    int reachNumber(int target)
    {
        target = abs(target);
        int k = 1;
        while (target > 0)
        {
            target -= k;
            k++;
        }
        k--;
        if (target % 2 == 0)
            return k;
        else
            return k + 1 + k % 2;
    }
};

// https://leetcode.com/problems/reach-a-number/discuss/386479/Python-O(1)-solution-with-explanation