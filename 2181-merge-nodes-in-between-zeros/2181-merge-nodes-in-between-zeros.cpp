/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* mergeNodes(ListNode *head)
        {
            ListNode *temp = head, *nexti;
            while (temp->next)
            {
                if (temp->val == 0)
                {
                    nexti = temp;
                    temp = temp->next;
                    continue;
                }
                nexti->val += temp->val;
                nexti->next = temp->next;
                temp = temp->next;
            }
            nexti->next = NULL;
            return head;
        }
};