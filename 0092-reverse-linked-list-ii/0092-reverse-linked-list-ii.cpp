/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverseBetween(ListNode *head, int left, int right)
        {
            if (left == right) return head;
            ListNode *start, *end, *temp = head, *prevs;
            for (int i = 1; i <= right; i++)
            {
                if (i == left - 1) prevs = temp;
                if (i == left) start = temp;
                if (i == right) end = temp;
                temp = temp->next;
            }
            ListNode *prev = start, *t2, *after = (end) ? end->next : NULL;
            if (start != head) prevs->next = end;
            temp = start->next;
            while (temp != end)
            {
                t2 = temp->next;
                temp->next = prev;
                prev = temp;
                temp = t2;
            }
            temp->next = prev;
            start->next = after;
            return (start != head) ? head : end;
        }
};