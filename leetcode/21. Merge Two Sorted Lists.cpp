/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *appendNode(ListNode *current, ListNode *&node)
    {
        current->next = node;
        node = node->next;
        return current->next;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(), *current = head;

        while (l1 or l2)
        {
            if (l1 and l2)
            {
                ListNode *&min_node = l1->val < l2->val ? l1 : l2;
                current = appendNode(current, min_node);
            }
            else if (l1)
            {
                current = appendNode(current, l1);
            }
            else if (l2)
            {
                current = appendNode(current, l2);
            }
        }

        return head->next;
    }
};