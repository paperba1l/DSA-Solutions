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

/*
    Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
*/
class Solution
{
public:
    int dfs(TreeNode *root, int &k)
    {
        if (root == NULL)
            return 0;

        int _l = dfs(root->left, k);
        if (_l > 0)
            return _l;

        k -= 1;
        if (k == 0)
            return root->val;

        int _r = dfs(root->right, k);
        return _r;
    }
    int kthSmallest(TreeNode *root, int k)
    {
        return dfs(root, k);
    }
};