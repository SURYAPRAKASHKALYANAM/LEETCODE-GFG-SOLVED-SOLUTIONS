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
    ListNode * ans;
    void helper(ListNode *head)
    {
        ListNode *temp = head;
        unordered_map<int, ListNode*> m;
        bool nextcall = false;
        int sum = 0;
        while (temp)
        {
            sum += temp->val;
            if (sum == 0)
            {
                ans = temp->next;
                helper(ans);
                break;
            }
            if (m.find(sum) != m.end())
            {
                auto first = m[sum];
                first->next = temp->next;
                nextcall = true;
                break;
            }
            m[sum] = temp;
            temp = temp->next;
        }
        if (nextcall) helper(head);
    }
    ListNode* removeZeroSumSublists(ListNode *head)
    {
        ans = head;
       	// ListNode *temp =head;
        helper(head);
        return ans;
    }
};