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
        ListNode* goNsteps(ListNode *node, int n)
        {
            while (n > 1 && node)
            {
                node = node->next;
                n--;
            }
            ListNode *toreturn = NULL;
            if (node)
            {
                toreturn = node->next;
                node->next = NULL;
            }
            return toreturn;
        }
    vector<ListNode*> splitListToParts(ListNode *head, int k)
    {
        ListNode *temp = head;
        vector<ListNode*> ans;
        int len = 0;
        while (temp) len++, temp = temp->next;
        int mod = (len > k) ? len % k : 0;
        int steplen = (len / k) + (mod ? 1 : 0);
        temp = head;
        while (k--)
        {
            ans.emplace_back(temp);
            temp = goNsteps(temp, steplen);
            if (--mod == 0) steplen--;
        }
        return ans;
    }
};