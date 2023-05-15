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
    ListNode* middleNode(ListNode* head) {
        // int c=0;
        // ListNode* temp=head;
        // while(temp!=NULL)
        // {
        //    c++;
        //     temp=temp->next;
        // }
        // c=((c%2==0)?(c/2+1):(c+1)/2);
        // while(c!=1)
        // {   c--; 
        //     head=head->next;
        // }
        // return head;
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
        
    }
};