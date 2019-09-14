/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      Max Continuous Series of 1s
 *  You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
 *  Find the position of zeros which when flipped will produce maximum continuous series of 1s.
**/
vector<int> Solution::maxone(vector<int> &a, int B)
{

    int l = 0, cnt = !a[0], tr = 0, tl = 0, ans = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == 0)
        {
            cnt++;
        }

        while (cnt > B)
        {
            if (a[l] == 0)
                cnt--;
            l++;
        }

        if ((i - l) > ans)
        {
            tr = i;
            tl = l;
            ans = i - l;
        }
    }

    vector<int> res;
    for (int i = tl; i <= tr; i++)
    {
        res.push_back(i);
    }
    return res;
}