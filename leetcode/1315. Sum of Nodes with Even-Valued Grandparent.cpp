/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int sumEvenGrandparentUtil(TreeNode *gp, TreeNode *p, TreeNode *curr)
    {
        int sm = 0;
        if (curr)
        {
            if (gp and gp->val % 2 == 0)
            {
                sm += curr->val;
            }
        }
        else
        {
            return 0;
        }
        int l = sumEvenGrandparentUtil(p, curr, curr->left);
        int r = sumEvenGrandparentUtil(p, curr, curr->right);
        return sm + l + r;
    }
    int sumEvenGrandparent(TreeNode *root)
    {
        return sumEvenGrandparentUtil(NULL, NULL, root);
    }
};