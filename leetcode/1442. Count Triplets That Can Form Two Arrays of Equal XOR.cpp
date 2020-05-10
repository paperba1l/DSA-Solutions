class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> xr(10000);

        xr[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            xr[i] = arr[i - 1] ^ xr[i - 1];
            //cout<<xr[i]<<endl;
        }

        int ans = 0;
        /*
        if xr[i] == xr[k],then there can be any j in range [i+1 .. k] to satisfy the condition
        */
        for (int i = 1; i < n; i++)
        {
            for (int k = i + 1; k <= n; k++)
            {
                if (xr[k] == xr[i - 1])
                {
                    ans += k - i;
                }
            }
        }

        return ans;
    }
};