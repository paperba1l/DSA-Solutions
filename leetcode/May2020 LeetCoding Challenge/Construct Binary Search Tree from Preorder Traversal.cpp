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
    TreeNode *prepareBst(int &idx, int lim, vector<int> lis)
    {
        // cout<<idx<<endl;
        if (idx >= lis.size() or lis.size() == 0 or lis[idx] >= lim)
            return NULL;

        int root_value = lis[idx];
        TreeNode *root = new TreeNode(root_value);
        ++idx;
        root->left = prepareBst(idx, root_value, lis);
        root->right = prepareBst(idx, lim, lis);

        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &lis)
    {
        int id = 0;
        TreeNode *root = prepareBst(id, INT_MAX, lis);

        return root;
    }
};