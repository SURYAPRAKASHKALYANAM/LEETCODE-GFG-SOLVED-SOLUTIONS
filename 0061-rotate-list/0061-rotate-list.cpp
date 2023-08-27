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
        ListNode* rotateRight(ListNode *head, int k)
        {
            if(!head) return 0;
            ListNode *temp = head, *end = head;
            int len = 1;
            while (temp->next)
            {
                temp = temp->next;
                len++;
            }
            temp->next = head;
            k = k % len;
            k = len - k - 1;
            while (k--) end = end->next;
            head = end->next;
            end->next = NULL;
            return head;
        }
};