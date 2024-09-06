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
        ListNode* modifiedList(vector<int> &nums, ListNode *head)
        {
            unordered_map<int, int> has;
            for (auto i: nums) has[i] = 1;
            ListNode *ans = NULL, *curr;

            while (head)
            {
                if (!has[head->val])
                {
                    if (!ans) curr = ans = head;
                    else
                    {
                        curr->next = head;
                        curr = head;
                    }
                }
                head = head->next;
            }
            if(curr) curr->next=NULL;
            return ans;
        }
};