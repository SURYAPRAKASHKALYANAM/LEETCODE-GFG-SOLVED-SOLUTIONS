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
        vector<int> nodesBetweenCriticalPoints(ListNode *head)
        {
            vector<int> ans;
            int pos = 2;
            ListNode *temp = head->next, *prev = head;
            while (temp && temp->next)
            {
                if ((temp->val > prev->val && temp->val > temp->next->val) ||
                    (temp->val < prev->val && temp->val < temp->next->val)) ans.emplace_back(pos);
                prev = temp;
                temp = temp->next;
                pos++;
            }
            if (ans.size() >= 2)
            {
                int mini = ans[1] - ans[0];
                for (int i = 2; i < ans.size(); i++) mini = min(mini, ans[i] - ans[i - 1]);
                return {mini,ans.back() - ans[0]};
            }
            return { -1,-1 };
        }
};