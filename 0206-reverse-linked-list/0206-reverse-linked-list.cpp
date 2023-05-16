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
    ListNode* reverseList(ListNode* temp) 
    {
        ListNode *prev_node=NULL,*next_node;
        while(temp)
        {
            next_node=temp->next;
            temp->next=prev_node;
            prev_node=temp;
            temp=next_node;
        }
        return prev_node;
    }
};