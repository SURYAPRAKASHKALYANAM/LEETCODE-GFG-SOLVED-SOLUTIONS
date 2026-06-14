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
        int pairSum(ListNode *head)
        {
            ListNode *slow = head, *fast = head;
            stack<int> s;
            while (fast && fast->next)
            {
                s.push(slow->val);	// STORE FIRST HALF OF THE ELEMENTS IN STACK
                slow = slow->next;
                fast = fast->next->next;
            }	//SLLOW POINTER REACHES MID AFTER THIS TRAVERSAL
            int maxi = 0;
            while (slow)	// BY POPPING AND ADDING THE STACK TOP
            {
               	//ELEMENT TO ITS TWIN PAIR IN SECOND HALF
                maxi = max(maxi, slow->val + s.top());
                s.pop();
                slow = slow->next;
            }
            return maxi;
        }
};