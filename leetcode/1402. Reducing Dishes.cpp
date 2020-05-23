class Solution
{
public:
    int maxSatisfaction(vector<int> &satis)
    {
        int is_all_neg = true;
        int len = satis.size();

        vector<int> neg, pos;
        for (int i = 0; i < len; i++)
        {
            if (satis[i] > 0)
            {
                is_all_neg = false;
                pos.push_back(satis[i]);
            }
            else
                neg.push_back(satis[i]);
        }
        if (is_all_neg)
            return 0;

        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());

        int sm_pos = 0, sm_pos_ele = 0;
        for (int i = 0; i < pos.size(); i++)
        {
            sm_pos += pos[i] * (i + 1);
            sm_pos_ele += pos[i];
        }

        int ans = sm_pos;
        for (int i = neg.size() - 1; i >= 0; i--)
        {
            int k = 0, sm_neg = 0;
            ;
            for (int j = i; j < neg.size(); j++)
            {
                sm_neg += neg[j] * (k + 1);
                k++;
            }

            ans = max(ans, sm_neg + sm_pos + k * sm_pos_ele);
        }

        return ans;
    }
};