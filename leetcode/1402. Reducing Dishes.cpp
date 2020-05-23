class Solution
{
public:
    int maxSatisfaction(vector<int> &satis)
    {
        int l_zero = -1;
        int len = satis.size();

        sort(satis.begin(), satis.end());
        int sm_pos_ele = 0, sm_pos = 0;

        for (int i = 0; i < len; i++)
        {
            if (satis[i] < 0)
            {
                l_zero = i;
            }
            else
            {
                sm_pos_ele += satis[i];
                sm_pos += satis[i] * (i - l_zero);
            }
        }

        if (l_zero == (len - 1))
            return 0;

        int ans = sm_pos,
            neg_sm = 0,
            prev_neg_sm = 0,
            neg_sm_ele = 0;

        for (int i = l_zero; i >= 0; i--)
        {
            neg_sm = satis[i] + prev_neg_sm + neg_sm_ele;

            ans = max(ans, neg_sm + sm_pos + (l_zero - i + 1) * sm_pos_ele);

            neg_sm_ele += satis[i];
            prev_neg_sm = neg_sm;
        }

        return ans;
    }
};