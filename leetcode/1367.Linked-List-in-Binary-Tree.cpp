/**
 *  @author:      skyhavoc
 *  created:      2020
 *  problem:      1367. Linked List in Binary Tree
 *  link:         https://leetcode.com/contest/weekly-contest-178/problems/linked-list-in-binary-tree/
**/

// toutorial - https://www.youtube.com/watch?v=DxJwb22b4UU

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool dfs2(TreeNode *root, ListNode *head)
    {
        if (!head)
            return 1;
        if (!root || root->val != head->val)
            return 0;
        return dfs2(root->left, head->next) || dfs2(root->right, head->next);
    }

    bool dfs(TreeNode *root, ListNode *head)
    {
        if (root->left && dfs(root->left, head))
            return 1;
        if (root->right && dfs(root->right, head))
            return 1;

        return dfs2(root, head);
    }

    bool isSubPath(ListNode *head, TreeNode *root)
    {
        return dfs(root, head);
    }
};