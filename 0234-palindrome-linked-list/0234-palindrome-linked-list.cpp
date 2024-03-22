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
        bool isPalindrome(ListNode *head)
        {
            stack<int> s;
            ListNode *fast = head, *slow = fast;
            while (fast && fast->next)
            {
                s.push(slow->val);
                slow = slow->next;
                fast = fast->next->next;
            }
            if (fast) slow = slow->next;
            while (slow && s.size())
            {
                if (slow->val != s.top()) return false;
                s.pop();
                slow = slow->next;
            }
            if (slow || s.size()) return false;
            return true;
        }
};