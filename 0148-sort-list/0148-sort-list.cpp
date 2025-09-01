/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                temp = temp->next = l1;
                l1 = l1->next;
            } else {
                temp = temp->next = l2;
                l2 = l2->next;
            }
        }
        temp->next = l1 ? l1 : l2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head->next;
        ListNode* middle = head;
        while (fast && fast->next) {
            slow = slow->next;
            middle = slow;
            fast = fast->next->next;
        }
        ListNode* left = middle->next;
        middle->next = nullptr;
        return merge(sortList(head), sortList(left));
    }
};
