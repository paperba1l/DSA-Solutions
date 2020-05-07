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
    vector<pair<int, int>> vec;
    void dfs(int parent, TreeNode *curr,
             int depth, int x, int y,
             pair<int, int> &ans1, pair<int, int> &ans2)
    {

        if (curr == NULL)
            return;

        if (curr->val == x)
        {
            ans1 = make_pair(depth, parent);
            return;
        }

        if (curr->val == y)
        {
            ans2 = make_pair(depth, parent);
            return;
        }

        dfs(curr->val, curr->left,
            depth + 1, x, y,
            ans1, ans2);
        dfs(curr->val, curr->right,
            depth + 1, x, y,
            ans1, ans2);
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        pair<int, int> ans1, ans2;
        ans1 = {-1, -1}, ans2 = {-1, -1};

        dfs(-1, root,
            0, x, y,
            ans1, ans2);

        cout << ans1.first << " " << ans2.first << " " << ans1.second << " " << ans2.second << endl;
        if (ans1.first == ans2.first and ans1.second != ans2.second)
        {
            return 1;
        }
        return 0;
    }
};