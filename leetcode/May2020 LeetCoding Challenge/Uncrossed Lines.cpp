/*
We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.       
*/
class Solution
{
public:
    int dp[502][502];

    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        int len1 = A.size(), len2 = B.size();

        /*
            if Ai == Bi then for dp(i,j) is 1 more than dp(i+1, j+1)
        */
        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                if (A[i] == B[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
                }
            }
        }

        return dp[0][0];
    }
};