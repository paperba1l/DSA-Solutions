/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *findInter(ListNode *headA, ListNode *headB)
    {
        while (true)
        {
            if (headA == headB)
                return headA;

            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    int findLength(ListNode *head)
    {
        int ans = 0;
        while (head)
        {
            head = head->next;
            ans++;
        }
        return ans;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len1 = findLength(headA);
        int len2 = findLength(headB);

        if (len1 == len2)
        {
            return findInter(headA, headB);
        }
        if (len1 < len2)
        {
            swap(headA, headB);
            swap(len1, len2);
        }

        int dif = len1 - len2;
        while (dif > 0)
        {
            headA = headA->next;
            dif--;
        }

        return findInter(headA, headB);
    }
};