/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        vector<int> nodesBetweenCriticalPoints(ListNode *head)
        {
            int begpos = -1, prevpos = -1, currpos = 2;
            int min_dis = INT_MAX;
            ListNode *temp = head->next, *prev = head;
            while (temp && temp->next)
            {
                if ((temp->val > prev->val && temp->val > temp->next->val) ||
                    (temp->val < prev->val && temp->val < temp->next->val))
                {
                    if (begpos == -1) begpos = currpos;
                    if (prevpos != -1) min_dis = min(min_dis, currpos - prevpos);
                    prevpos = currpos;
                }
                prev = temp;
                temp = temp->next;
                currpos++;
            }
            if (prevpos != begpos) return {min_dis,prevpos - begpos };
            return { -1,-1 };
        }
};