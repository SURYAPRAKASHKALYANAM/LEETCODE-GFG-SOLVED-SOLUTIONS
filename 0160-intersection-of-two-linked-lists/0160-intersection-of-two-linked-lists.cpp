/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* getIntersectionNode(ListNode *firstHead, ListNode *secondHead)
        {
            while (firstHead)
            {
                ListNode *tem = secondHead;
                while (tem)
                {
                    if (tem== firstHead) return tem;
                    tem = tem->next;
                }
                firstHead = firstHead->next;
            }
            return NULL;
        }
};