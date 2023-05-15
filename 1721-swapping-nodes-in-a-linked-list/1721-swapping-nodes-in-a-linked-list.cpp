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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* temp=head;
        ListNode* temp1;
        ListNode* temp2;
        for(int i=0;i<k-1;i++)
        {
            temp=temp->next;
        }
        temp1=temp;
        temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        c-=k;
        temp=head;
        for(int i=0;i<c;i++)
            temp=temp->next;
        temp2=temp;
        swap(temp1->val,temp2->val);
        return head;
    }
};