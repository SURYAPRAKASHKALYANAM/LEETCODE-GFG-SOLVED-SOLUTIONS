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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int c=0;
        temp=head;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        c-=n+1;
        temp=head;
        if (c==-1)
            head=head->next;
        for(int i=0;i<c;i++)
        {
            temp=temp->next;
        }
        if(temp->next!=NULL) temp->next=temp->next->next;
        else head=NULL;
        return head;

    }
};