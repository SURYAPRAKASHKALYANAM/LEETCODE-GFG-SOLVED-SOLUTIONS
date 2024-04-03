/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode* first=head,*second=head;
        while(second && second->next)
        {
            while(second && second->next && second->val==second->next->val) second=second->next;
            first->next=second->next;
            first=first->next;
            second=second->next;
        }
        return head;
    }
};