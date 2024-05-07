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
        ListNode* doubleIt(ListNode *head)
        {
            int curr=0;
            stack<int> s;
            while (head)
            {
                s.push(head->val);
                head = head->next;
            }
            while (!s.empty() || curr != 0)
            {
                if (s.size())
                {
                    curr = curr + s.top() *2;
                    s.pop();
                }
                head = new ListNode(curr % 10, head);
                curr = curr / 10;
            }
            return head;
        }
};