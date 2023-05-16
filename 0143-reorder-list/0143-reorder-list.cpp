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
        void reorderList(ListNode *head)
        {
            ListNode *slow = head, *fast = head;
            while (fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode *temp = slow->next;
            slow->next = NULL;
            stack<ListNode*> s;
            while (temp)
            {
                s.push(temp);
                temp = temp->next;
            }
            temp = head;
            while (!s.empty())
            {
                fast = s.top();
                s.pop();
                slow = temp->next;
                temp->next = fast;
                fast->next = slow;
                temp = slow;
            }
        }
};