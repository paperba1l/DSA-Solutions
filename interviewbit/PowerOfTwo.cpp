/**
 *  @author:      skyhavoc
 *  created:      2019
**/
int maxSortedAdjacentDiff(int n)
{

    for (int p = 2; p < 32; p++)
    {
        for (int i = 2; pow(i, p) <= INT_MAX and i <= sqrt(INT_MAX); i++)
        {
            if (pow(i, p) == n)
                return 1;
        }
    }
    return 0;
}