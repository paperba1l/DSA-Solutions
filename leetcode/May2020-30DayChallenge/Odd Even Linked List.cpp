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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *oddhead = head;
        if (oddhead == NULL)
            return head;

        ListNode *evenhead = head->next;

        while (evenhead != NULL and evenhead->next != NULL)
        {
            ListNode *t = evenhead->next;
            ListNode *tnext = t->next;

            ListNode *oddlistnext = oddhead->next;

            // join to to oddlist
            oddhead->next = t;

            // join evenlist
            evenhead->next = t->next;
            evenhead = tnext;

            // merge oddlist to evenlist
            oddhead = t;
            t->next = oddlistnext;
        }
        return head;
    }
}; //[2,1,3,5,6,4,7]