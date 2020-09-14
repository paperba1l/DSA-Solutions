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
    bool findTarget(TreeNode *root, int k)
    {

        stack<TreeNode *> stk1, stk2;
        TreeNode *cur1 = root, *cur2 = root;

        while (cur1 != NULL)
        {
            stk1.push(cur1);
            cur1 = cur1->left;
        }

        while (cur2 != NULL)
        {
            stk2.push(cur2);
            cur2 = cur2->right;
        }

        while (stk1.top() != stk2.top())
        {
            int v1 = stk1.top()->val, v2 = stk2.top()->val;

            if (v1 + v2 == k)
            {
                return true;
            }
            else if (v1 + v2 < k)
            {
                cur1 = stk1.top()->right;
                stk1.pop();
                while (cur1 != NULL)
                {
                    stk1.push(cur1);
                    cur1 = cur1->left;
                }
            }
            else
            {
                cur2 = stk2.top()->left;
                stk2.pop();
                while (cur2 != NULL)
                {
                    stk2.push(cur2);
                    cur2 = cur2->right;
                }
            }
        }
        return false;
    }
};